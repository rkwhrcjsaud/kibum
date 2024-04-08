#include <iostream>
#include <vector>
#include <queue>

int N;
int dp[501];

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N;
    std::vector<std::vector<int> > v(N + 1);
    std::vector<int> indegree(N + 1, 0);
    std::vector<int> time(N + 1, 0);
    std::queue<int> q;
    for (int i = 1; i <= N; i++)
    {
        int t;
        std::cin >> t;
        time[i] = t;
        while (true)
        {
            int tmp;
            std::cin >> tmp;
            if (tmp == -1)
                break ;
            v[tmp].push_back(i);
            indegree[i]++;
        }
    }
    for (int i = 1; i <= N; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
            dp[i] = time[i];
        }
    }
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        for (int i = 0; i < v[cur].size(); i++)
        {
            int next = v[cur][i];
            dp[next] = std::max(dp[next], dp[cur] + time[next]);
            indegree[next]--;
            if (indegree[next] == 0)
                q.push(next);
        }
    }
    for (int i = 1; i <= N; i++)
        std::cout << dp[i] << '\n';
    return 0;
}