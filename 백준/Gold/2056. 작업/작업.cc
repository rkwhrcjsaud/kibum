#include <iostream>
#include <queue>
#include <vector>

int N;
int arr[10001];
int dp[10001];
int indegree[10001];
std::vector<int> graph[10001];

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N;
    for (int i = 1; i <= N; i++)
    {
        std::cin >> arr[i];
        int M;
        std::cin >> M;
        for (int j = 0; j < M; j++)
        {
            int tmp;
            std::cin >> tmp;
            graph[tmp].push_back(i);
            indegree[i]++;
        }
    }
    std::queue<int> q;
    for (int i = 1; i <= N; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
            dp[i] = arr[i];
        }
    }
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        for (int i = 0; i < graph[cur].size(); i++)
        {
            int next = graph[cur][i];
            dp[next] = std::max(dp[next], dp[cur] + arr[next]);
            indegree[next]--;
            if (indegree[next] == 0)
                q.push(next);
        }
    }
    int max = 0;
    for (int i = 1; i <= N; i++)
        max = std::max(max, dp[i]);
    std::cout << max << '\n';
}