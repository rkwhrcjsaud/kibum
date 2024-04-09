#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

int N, M;
int dp[1001];
int indegree[1001];
std::vector<std::vector<int> > graph(1001);

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N >> M;
    for (int i = 0; i < M; i++)
    {
        int X, Y;
        std::cin >> X >> Y;
        graph[X].push_back(Y);
        indegree[Y]++;
    }
    std::queue<int> q;
    for (int i = 1; i <= N; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
            dp[i] = 1;
        }
    }
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        for (int i = 0; i < graph[cur].size(); i++)
        {
            int next = graph[cur][i];
            indegree[next]--;
            if (indegree[next] == 0)
            {
                q.push(next);
                dp[next] = std::max(dp[next], dp[cur] + 1);
            }
        }
    }
    for (int i = 1; i <= N; i++)
        std::cout << dp[i] << ' ';
    std::cout << '\n';
}