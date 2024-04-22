#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

int N, M, C;
const int MOD = 1000007;
int arcade[51][51];
int dp[52][52][52][52];

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N >> M >> C;
    for (int i = 1; i <= C; i++)
    {
        int x, y;
        std::cin >> x >> y;
        arcade[x][y] = i;
    }
    dp[1][1][arcade[1][1] ? 1 : 0][arcade[1][1]] = 1;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            if (i == 1 && j == 1)
                continue;
            if (arcade[i][j] > 0)
            {
                for (int k = 0; k < arcade[i][j]; k++)
                {
                    for (int l = 0; l <= k; l++)
                    {
                        dp[i][j][l + 1][arcade[i][j]] += dp[i - 1][j][l][k] + dp[i][j - 1][l][k];
                        dp[i][j][l + 1][arcade[i][j]] %= MOD;
                    }
                }
            }
            else
            {
                for (int k = 0; k <= C; k++)
                {
                    for (int l = 0; l <= k; l++)
                    {
                        dp[i][j][l][k] = dp[i - 1][j][l][k] + dp[i][j - 1][l][k];
                        dp[i][j][l][k] %= MOD;
                    }
                }
            }
        }
    }
    for (int i = 0; i <= C; i++)
    {
        int result = 0;
        for (int j = 0; j <= C; j++)
            result = (result + dp[N][M][i][j]) % MOD;
        std::cout << result << ' ';
    }
    std::cout << '\n';
}