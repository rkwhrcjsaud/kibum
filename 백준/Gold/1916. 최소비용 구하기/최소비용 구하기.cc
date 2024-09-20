#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

int N, M;
int s, e;
vector<pair<int, int> > v[1001];

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    cin >> N >> M;
    for (int i = 0; i < M; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        v[a].push_back(make_pair(b, c));
    }
    cin >> s >> e;
    priority_queue<pair<int, int> > pq;
    vector<int> dist(N + 1, 1e9);
    pq.push(make_pair(0, s));
    dist[s] = 0;
    while (!pq.empty())
    {
        int here = pq.top().second;
        int cost = -pq.top().first;
        pq.pop();
        if (dist[here] < cost)
            continue;
        for (int i = 0; i < v[here].size(); i++)
        {
            int there = v[here][i].first;
            int nextDist = cost + v[here][i].second;
            if (dist[there] > nextDist)
            {
                dist[there] = nextDist;
                pq.push(make_pair(-nextDist, there));
            }
        }
    }
    cout << dist[e] << '\n';
}