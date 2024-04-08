#include <iostream>

int N;
int map[510][510];
int dp[510][510];

void dfs(int y, int x)
{
    if (dp[y][x] != -1)
        return ;
    dp[y][x] = 1;
    if (y > 1 && map[y][x] < map[y - 1][x])
    {
        dfs(y - 1, x);
        dp[y][x] = std::max(dp[y][x], dp[y - 1][x] + 1);
    }
    if (y < N && map[y][x] < map[y + 1][x])
    {
        dfs(y + 1, x);
        dp[y][x] = std::max(dp[y][x], dp[y + 1][x] + 1);
    }
    if (x > 1 && map[y][x] < map[y][x - 1])
    {
        dfs(y, x - 1);
        dp[y][x] = std::max(dp[y][x], dp[y][x - 1] + 1);
    }
    if (x < N && map[y][x] < map[y][x + 1])
    {
        dfs(y, x + 1);
        dp[y][x] = std::max(dp[y][x], dp[y][x + 1] + 1);
    }
}

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
            std::cin >> map[i][j];
    }
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
            dp[i][j] = -1;
    }
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
            dfs(i, j);
    }
    int max = 0;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
            max = std::max(max, dp[i][j]);
    }
    std::cout << max << '\n';
}