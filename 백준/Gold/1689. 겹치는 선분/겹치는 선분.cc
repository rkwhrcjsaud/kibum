#include <iostream>
#include <queue>

int N;
std::priority_queue <std::pair<int, int>, std::vector<std::pair<int, int> >, std::greater<std::pair<int, int> > > pq;

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N;
    for (int i = 0; i < N; i++)
    {
        int s, e;
        std::cin >> s >> e;
        pq.push(std::make_pair(s, 1));
        pq.push(std::make_pair(e, -1));
    }
    int max = 0;
    int cnt = 0;
    for (; !pq.empty();)
    {
        int i = pq.top().first;
        for (; !pq.empty() && i == pq.top().first; pq.pop())
            cnt += pq.top().second;
        max = max > cnt ? max : cnt;
    }
    std::cout << max << '\n';
}