#include <iostream>
#include <queue>
#define INF 1000000000

int N, K;
int dist[100010];
int left[100010];
int right[100010];
bool visited[100010];
std::priority_queue< std::pair<int, int>, std::vector< std::pair<int, int> >, std::greater< std::pair<int, int> > > pq;

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N >> K;
    pq.push(std::make_pair(INF, 1));
    pq.push(std::make_pair(INF, N + 1));
    dist[1] = INF;
    dist[N + 1] = INF;
    right[1] = 2;
    left[N + 1] = N;
    int tmp1;
    std::cin >> tmp1;
    for (int i = 2; i <= N; i++)
    {
        int tmp2;
        std::cin >> tmp2;
        dist[i] = tmp2 - tmp1;
        left[i] = i - 1;
        right[i] = i + 1;
        pq.push(std::make_pair(dist[i], i));
        tmp1 = tmp2;
    }
    int ans = 0;
    for (int i = 0; i < K; i++)
    {
        while (visited[pq.top().second])
            pq.pop();
        int d = pq.top().first;
        int cur = pq.top().second;
        pq.pop();
        ans += d;
        dist[cur] = dist[left[cur]] + dist[right[cur]] - dist[cur];
        pq.push(std::make_pair(dist[cur], cur));
        visited[left[cur]] = true;
        visited[right[cur]] = true;
        left[cur] = left[left[cur]];
        right[cur] = right[right[cur]];
        right[left[cur]] = cur;
        left[right[cur]] = cur;
    }
    std::cout << ans << '\n';
}