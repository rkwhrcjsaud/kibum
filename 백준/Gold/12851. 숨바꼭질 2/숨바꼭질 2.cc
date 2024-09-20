#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

int N, K;

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    cin >> N >> K;
    vector<int> dist(200001, -1);
    priority_queue<pair<int, int> > pq;
    vector<int> cnt(200001, 0);
    pq.push(make_pair(0, N));
    dist[N] = 0;
    cnt[N] = 1;
    while (!pq.empty())
    {
        int here = pq.top().second;
        int cost = -pq.top().first;
        pq.pop();
        if (dist[here] < cost)
            continue;
        if (here % 2 == 0 && dist[here / 2] == cost - 1)
            cnt[here] += cnt[here / 2];
        if (here + 1 <= 200000 && dist[here + 1] == cost - 1)
            cnt[here] += cnt[here + 1];
        if (here - 1 >= 0 && dist[here - 1] == cost - 1)
            cnt[here] += cnt[here - 1];
        if (here * 2 <= 200000 && dist[here * 2] == -1)
        {
            dist[here * 2] = cost + 1;
            pq.push(make_pair(-cost - 1, here * 2));
        }
        if (here + 1 <= 200000 && dist[here + 1] == -1)
        {
            dist[here + 1] = cost + 1;
            pq.push(make_pair(-cost - 1, here + 1));
        }
        if (here - 1 >= 0 && dist[here - 1] == -1)
        {
            dist[here - 1] = cost + 1;
            pq.push(make_pair(-cost - 1, here - 1));
        }
    }
    cout << dist[K] << '\n' << cnt[K] << '\n';
}