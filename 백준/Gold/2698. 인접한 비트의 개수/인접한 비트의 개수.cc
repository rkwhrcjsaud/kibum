#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

int T;
int dp[101][101][2];

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> T;
    while (T--)
    {
        int N, K;
        std::cin >> N >> K;
        dp[1][0][0] = 1;
        dp[1][0][1] = 1;
        for (int i = 2; i <= N; i++)
        {
            dp[i][0][0] = dp[i - 1][0][0] + dp[i - 1][0][1];
            dp[i][0][1] = dp[i - 1][0][0];
            for (int j = 1; j <= K; j++)
            {
                dp[i][j][0] = dp[i - 1][j][0] + dp[i - 1][j][1];
                dp[i][j][1] = dp[i - 1][j][0] + dp[i - 1][j - 1][1];
            }
        }
        std::cout << dp[N][K][0] + dp[N][K][1] << '\n';
    }
}