#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <sstream>
#include <map>

int T, N;
long long dp[1000001][2];
const int MOD = 1e9 + 7;

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> T;
    while (T--)
    {
        std::cin >> N;
        dp[1][0] = 3;
        dp[1][1] = 4;
        if (dp[N][0])
        {
            std::cout << (dp[N][0] + dp[N][1]) % MOD << '\n';
            continue;
        }
        for (int i = 2; i <= N; i++)
        {
            dp[i][0] = dp[i - 1][0] * 3 + dp[i - 1][1];
            dp[i][1] = dp[i - 1][0] * 4 + dp[i - 1][1] * 2;
            dp[i][0] %= MOD;
            dp[i][1] %= MOD;
        }
        std::cout << (dp[N][0] + dp[N][1]) % MOD << '\n';
    }
}