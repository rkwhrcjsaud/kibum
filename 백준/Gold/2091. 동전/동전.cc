#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

int X, A, B, C, D;
int dp[10001][5];
int coin[2][5];

void solve()
{
    for (int i = 1; i <= X; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (dp[i][j] == -1)
                dp[i][j] = 0;
            if (i < coin[0][j])
                continue;
            if (dp[i - coin[0][j]][4] > dp[i][4])
            {
                if (coin[1][j] > dp[i - coin[0][j]][j])
                {
                    for (int k = 0; k < 4; k++)
                        dp[i][k] = dp[i - coin[0][j]][k];
                    dp[i][4] = dp[i - coin[0][j]][4] + 1;
                    dp[i][j]++;
                }
            }
        }
    }
    for (int i = 0; i < 4; i++)
        std::cout << dp[X][i] << ' ';
}

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> X;
    for (int i = 0; i < 4; i++)
        std::cin >> coin[1][i];
    coin[0][0] = 1;
    coin[0][1] = 5;
    coin[0][2] = 10;
    coin[0][3] = 25;
    memset(dp, -1, sizeof(dp));
    for (int i = 0; i <= 4; i++)
        dp[0][i] = 0;
    solve();
}