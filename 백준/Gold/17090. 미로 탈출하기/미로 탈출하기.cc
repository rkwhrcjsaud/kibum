#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

int N, M;
std::string map[501];
int dp[501][501];

bool solve(int y, int x)
{
    if (y < 0 || y >= N || x < 0 || x >= M)
        return true;
    if (dp[y][x] != -1)
        return dp[y][x];
    dp[y][x] = 0;
    if (map[y][x] == 'U')
        dp[y][x] = solve(y - 1, x);
    else if (map[y][x] == 'D')
        dp[y][x] = solve(y + 1, x);
    else if (map[y][x] == 'L')
        dp[y][x] = solve(y, x - 1);
    else if (map[y][x] == 'R')
        dp[y][x] = solve(y, x + 1);
    return dp[y][x];
}

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N >> M;
    for (int i = 0; i < N; ++i)
        std::cin >> map[i];
    int ans = 0;
    std::fill(&dp[0][0], &dp[500][500], -1);
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            if (solve(i, j))
                ans++;
        }
    }
    std::cout << ans << '\n';
}