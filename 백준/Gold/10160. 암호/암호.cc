#include <iostream>
#include <vector>
#include <algorithm>

int N, K;
long long dp[1000001][7];
const int MOD = 1e9 + 9;

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N >> K;
    dp[0][0] = 1;
    for (int i = 1; i <= N; i++)
    {
        dp[i][0] = dp[i - 1][0] * (K - 1);
        for (int j = 1; j < 7; j++)
            dp[i][0] += dp[i - 1][j] * (K - 2);
        dp[i][1] = dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][3] + dp[i - 1][4] + dp[i - 1][5];
        dp[i][2] = dp[i - 1][1];
        dp[i][3] = dp[i - 1][2];
        dp[i][4] = dp[i - 1][3];
        dp[i][5] = dp[i - 1][2] + dp[i - 1][6];
        dp[i][6] = dp[i - 1][5];
        for (int j = 0; j < 7; j++)
            dp[i][j] %= MOD;
    }
    long long ans = 0;
    for (int i = 0; i < 7; i++)
        ans += dp[N][i];
    std::cout << ans % MOD << '\n';
}
