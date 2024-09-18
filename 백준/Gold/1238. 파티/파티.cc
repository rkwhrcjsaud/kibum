#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#include <map>

using namespace std;

int N, M, X;
vector<vector<pair<int, int> > > adj;
vector<vector<pair<int, int> > > adj2;
vector<int> dist;
vector<int> dist2;

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    cin >> N >> M >> X;
    adj.resize(N + 1);
    adj2.resize(N + 1);
    dist.resize(N + 1, 1e9);
    dist2.resize(N + 1, 1e9);
    for (int i = 0; i < M; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back(make_pair(w, v));
        adj2[v].push_back(make_pair(w, u));
    }
    priority_queue<pair<int, int> > pq;
    pq.push(make_pair(0, X));
    dist[X] = 0;
    while (!pq.empty())
    {
        int here = pq.top().second;
        int cost = -pq.top().first;
        pq.pop();
        if (dist[here] < cost)
            continue;
        for (int i = 0; i < adj[here].size(); i++)
        {
            int there = adj[here][i].second;
            int nextDist = cost + adj[here][i].first;
            if (dist[there] > nextDist)
            {
                dist[there] = nextDist;
                pq.push(make_pair(-nextDist, there));
            }
        }
    }
    pq.push(make_pair(0, X));
    dist2[X] = 0;
    while (!pq.empty())
    {
        int here = pq.top().second;
        int cost = -pq.top().first;
        pq.pop();
        if (dist2[here] < cost)
            continue;
        for (int i = 0; i < adj2[here].size(); i++)
        {
            int there = adj2[here][i].second;
            int nextDist = cost + adj2[here][i].first;
            if (dist2[there] > nextDist)
            {
                dist2[there] = nextDist;
                pq.push(make_pair(-nextDist, there));
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= N; i++)
        ans = max(ans, dist[i] + dist2[i]);
    cout << ans << '\n';
}