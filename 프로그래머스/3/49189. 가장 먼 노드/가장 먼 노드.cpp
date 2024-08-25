#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;
vector<int> v[20001];
int dp[20001];
const int INF = 1e9;

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    for (int i = 0; i <= n; i++)
        dp[i] = INF;
    for (int i = 0; i < edge.size(); i++)
    {
        int a = edge[i][0];
        int b = edge[i][1];
        v[a].push_back(b);
        v[b].push_back(a);
    }
    priority_queue<pair<int, int>> pq;
    pq.push(make_pair(0, 1));
    dp[1] = 0;
    int max_dist = -1;
    while (!pq.empty())
    {
        int curr = pq.top().second;
        int w = -pq.top().first;
        if (dp[curr] < w)
            continue ;
        dp[curr] = w;
        max_dist = max(max_dist, w);
        pq.pop();
        for (int i = 0; i < v[curr].size(); i++)
        {
            int next = v[curr][i];
            int nw = w + 1;
            if (nw < dp[next])
            {
                dp[next] = nw;
                pq.push(make_pair(-nw, next));
            }
        }
    }
    for (int i = 1; i <= n; i++)
        if (max_dist == dp[i])
            answer++;
    return answer;
}