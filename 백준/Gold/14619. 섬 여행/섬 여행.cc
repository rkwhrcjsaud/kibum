#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>

int N, M, T, A, K;
int height[101];
std::vector<int> adj[101];
int dp[101][501]; // dp[i][j] = i번째 노드에서 j번 이동했을 때의 최소 높이

int solve(int node, int k)
{
    if (k == 0)
        return dp[node][k];
    if (dp[node][k] != -1)
        return dp[node][k];
    dp[node][k] = 1e9;
    for (int i = 0; i < adj[node].size(); i++)
    {
        int next = adj[node][i];
        dp[node][k] = std::min(dp[node][k], solve(next, k - 1));
    }
    return dp[node][k];
}

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N >> M;
    for (int i = 1; i <= N; i++)
        std::cin >> height[i];
    for (int i = 1; i <= M; i++)
    {
        int a, b;
        std::cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    memset(dp, -1, sizeof(dp));
    for (int i = 1; i <= N; i++)
        dp[i][0] = height[i];
    std::cin >> T;
    while (T--)
    {
        std::cin >> A >> K;
        int result = solve(A, K);
        if (result == 1e9)
            std::cout << "-1\n";
        else
            std::cout << result << '\n';
    }
}
