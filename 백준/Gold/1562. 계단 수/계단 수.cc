#include <iostream>
#include <queue>
#include <vector>

int N;
const int MOD = 1000000000;
int dp[101][10][1 << 10];

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N;
    for (int i = 1; i <= 9; i++)
        dp[1][i][1 << i] = 1;
    for (int i = 2; i <= N; i++)
    {
        for (int j = 0; j <= 9; j++)
        {
            for (int k = 0; k < (1 << 10); k++)
            {
                if (j == 0)
                    dp[i][j][k | (1 << j)] = (dp[i][j][k | (1 << j)] + dp[i - 1][j + 1][k]) % MOD;
                else if (j == 9)
                    dp[i][j][k | (1 << j)] = (dp[i][j][k | (1 << j)] + dp[i - 1][j - 1][k]) % MOD;
                else
                {
                    dp[i][j][k | (1 << j)] = (dp[i][j][k | (1 << j)] + dp[i - 1][j - 1][k]) % MOD;
                    dp[i][j][k | (1 << j)] = (dp[i][j][k | (1 << j)] + dp[i - 1][j + 1][k]) % MOD;
                }
            }
        }
    }
    int result = 0;
    for (int i = 0; i <= 9; i++)
        result = (result + dp[N][i][(1 << 10) - 1]) % MOD;
    std::cout << result << '\n';
}