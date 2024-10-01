#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#include <cmath>

using namespace std;

int T;
int N, K;

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    cin >> T;
    while (T--)
    {
        cin >> N >> K;
        vector<int> build_time(N + 1);
        for (int i = 1; i <= N; i++)
            cin >> build_time[i];
        vector<vector<int> > adj(N + 1);
        vector<int> indegree(N + 1, 0);
        vector<int> dp(N + 1, 0);
        for (int i = 0; i < K; i++)
        {
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            indegree[b]++;
        }
        queue<int> q;
        for (int i = 1; i <= N; i++)
        {
            if (indegree[i] == 0)
            {
                q.push(i);
                dp[i] = build_time[i];
            }
        }
        while (!q.empty())
        {
            int cur = q.front();
            q.pop();
            for (int i = 0; i < adj[cur].size(); i++)
            {
                int next = adj[cur][i];
                dp[next] = max(dp[next], dp[cur] + build_time[next]);
                indegree[next]--;
                if (indegree[next] == 0)
                    q.push(next);
            }
        }
        int W;
        cin >> W;
        cout << dp[W] << '\n';
    }
}