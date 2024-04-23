#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

int N;
int map[1001][1001];
int dp[1001][1001][3];

int prev(int k)
{
    return k == 0 ? 2 : k - 1;
}

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            std::cin >> map[i][j];
            if (map[i][j] == 0)
                dp[i][j][0] = 1;
        }
    }
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            for (int k = 0; k <= 2; k++)
            {
                dp[i][j][k] = std::max(dp[i][j][k], std::max(dp[i - 1][j][k], dp[i][j - 1][k]));
                if (map[i][j] == k)
                {
                    if (dp[i - 1][j][prev(k)] != 0)
                        dp[i][j][k] = std::max(dp[i][j][k], 1 + dp[i - 1][j][prev(k)]);
                    if (dp[i][j - 1][prev(k)] != 0)
                        dp[i][j][k] = std::max(dp[i][j][k], 1 + dp[i][j - 1][prev(k)]);
                }
            }
        }
    }
    std::cout << std::max(dp[N][N][0], std::max(dp[N][N][1], dp[N][N][2])) << '\n';
}