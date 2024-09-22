#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

int N, M, R;
vector<int> item;
vector<vector<pair<int, int> > > edge;
vector<vector<int> > dist;

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    cin >> N >> M >> R;
    item.resize(N + 1);
    for (int i = 1; i <= N; i++)
        cin >> item[i];
    edge.resize(N + 1, vector<pair<int, int> >());
    for (int i = 0; i < R; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        edge[a].push_back(make_pair(b, c));
        edge[b].push_back(make_pair(a, c));
    }
    dist.resize(N + 1, vector<int>(N + 1, 1e9));
    for (int i = 1; i <= N; i++)
    {
        priority_queue<pair<int, int> > pq;
        pq.push(make_pair(0, i));
        dist[i][i] = 0;
        while (!pq.empty())
        {
            int here = pq.top().second;
            int cost = -pq.top().first;
            pq.pop();
            if (dist[i][here] < cost)
                continue;
            for (int j = 0; j < edge[here].size(); j++)
            {
                int there = edge[here][j].first;
                int nextDist = cost + edge[here][j].second;
                if (dist[i][there] > nextDist)
                {
                    dist[i][there] = nextDist;
                    pq.push(make_pair(-nextDist, there));
                }
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= N; i++)
    {
        int sum = 0;
        for (int j = 1; j <= N; j++)
            if (dist[i][j] <= M)
                sum += item[j];
        ans = max(ans, sum);
    }
    cout << ans << '\n';
}