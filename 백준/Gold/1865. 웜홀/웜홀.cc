#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#include <map>

using namespace std;

int T, N, M, W;

bool bellman_ford(int start, vector<vector<pair<int, int> > > &adj)
{
    vector<int> dist(N + 1, 1e9);
    dist[start] = 0;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            for (int k = 0; k < adj[j].size(); k++)
            {
                int next = adj[j][k].second;
                int next_dist = adj[j][k].first;
                if (dist[next] > dist[j] + next_dist)
                {
                    dist[next] = dist[j] + next_dist;
                    if (i == N)
                        return true;
                }
            }
        }
    }
    return false;
}

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    cin >> T;
    while (T--)
    {
        vector<vector<pair<int, int> > > adj;
        adj.resize(501);
        cin >> N >> M >> W;
        for (int i = 0; i < M; i++)
        {
            int s, e, t;
            cin >> s >> e >> t;
            adj[s].push_back(make_pair(t, e));
            adj[e].push_back(make_pair(t, s));
        }
        for (int i = 0; i < W; i++)
        {
            int s, e, t;
            cin >> s >> e >> t;
            adj[s].push_back(make_pair(-t, e));
        }
        if (bellman_ford(1, adj))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}