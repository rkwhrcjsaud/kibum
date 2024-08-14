#include <string>
#include <vector>
#include <queue>

using namespace std;
vector<int> v[100001];
int dp[100001];
queue<int> q;

vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int destination) {
    vector<int> answer;
    for (int i = 0; i < roads.size(); i++)
    {
        int a = roads[i][0];
        int b = roads[i][1];
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for (int i = 0; i <= n; i++)
        dp[i] = -1;
    dp[destination] = 0;
    q.push(destination);
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        for (int i = 0; i < v[node].size(); i++)
        {
            int next = v[node][i];
            if (dp[next] != -1)
                continue;
            dp[next] = dp[node] + 1;
            q.push(next);
        }
    }
    for (int i = 0; i < sources.size(); i++)
        answer.push_back(dp[sources[i]]);
    return answer;
}