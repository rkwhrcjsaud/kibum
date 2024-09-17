#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <queue>

using namespace std;

int N, M;
vector<int> v[101];

int dijkstra(int start)
{
    vector<int> dist(N + 1, 1e7);
    priority_queue<pair<int, int> > pq;

    dist[start] = 0;
    pq.push(make_pair(0, start));

    while (!pq.empty())
    {
        int cur_dist = -pq.top().first;
        int cur_node = pq.top().second;
        pq.pop();

        for (int i = 0; i < v[cur_node].size(); i++)
        {
            int next_node = v[cur_node][i];
            int next_dist = cur_dist + 1;

            if (dist[next_node] > next_dist)
            {
                dist[next_node] = next_dist;
                pq.push(make_pair(-next_dist, next_node));
            }
        }
    }
    int ret = 0;
    for (int i = 1; i <= N; i++)
        ret += dist[i];
    return ret;
}

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    cin >> N >> M;
    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    int ans = 1e7;
    int ret = 0;
    for (int i = 1; i <= N; i++)
    {
        int tmp = dijkstra(i);
        if (tmp < ans)
        {
            ans = tmp;
            ret = i;
        }
    }
    cout << ret << '\n';
}