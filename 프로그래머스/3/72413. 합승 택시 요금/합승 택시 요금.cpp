#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;
vector<pair<int, int>> v[201];
vector<int> distA;
vector<int> distB;
vector<int> distC;
const int INF = 6e8;

void minDist(int start, vector<int> &dist)
{
    dist[start] = 0;
    priority_queue<pair<int, int>> q;
    q.push(make_pair(start, 0));
    while (!q.empty())
    {
        int cur = q.top().first;
        int w = -q.top().second;
        q.pop();
        if (dist[cur] < w)
            continue ;
        for (int i = 0; i < v[cur].size(); i++)
        {
            int next = v[cur][i].first;
            int nw = w + v[cur][i].second;
            if (dist[next] > nw)
            {
                dist[next] = nw;
                q.push(make_pair(next, -nw));
            }
        }
    }
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = INF;
    distA.resize(n + 1, INF);
    distB.resize(n + 1, INF);
    distC.resize(n + 1, INF);
    for (int i = 0; i < fares.size(); i++)
    {
        v[fares[i][0]].push_back(make_pair(fares[i][1], fares[i][2]));
        v[fares[i][1]].push_back(make_pair(fares[i][0], fares[i][2]));
    }
    minDist(a, distA);
    minDist(b, distB);
    minDist(s, distC);
    for (int i = 1; i <= n; i++)
    {
        int w = distA[i] + distB[i] + distC[i];
        if (w < answer)
            answer = w;
    }
    return answer;
}