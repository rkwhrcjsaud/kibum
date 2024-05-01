#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

int N, K;
int dp[501][501];

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N >> K;
    for (int i = 1; i <= K; i ++)
    {
        for (int j = 1; j <= N; j++)
        {
            if (i == 1)
            {
                dp[i][j] = j;
                continue ;
            }
            if (i > j)
            {
                dp[i][j] = dp[i - 1][j];
                continue ;
            }
            dp[i][j] = 1e9;
            for (int k = 1; k <= j; k++)
                dp[i][j] = std::min(dp[i][j], std::max(dp[i - 1][k - 1], dp[i][j - k]) + 1);
        }
    }
    std::cout << dp[K][N] << '\n';
}