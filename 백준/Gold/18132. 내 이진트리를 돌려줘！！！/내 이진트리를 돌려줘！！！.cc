#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <map>

int T, E;
const int MOD = 1e9 + 7;
long long dp[5001];

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> T;
    dp[0] = 1;
    dp[1] = 2;
    for (int i = 2; i <= 5000; i++)
    {
        dp[i] = (dp[i - 1] * 2) % MOD;
        for (int j = 0; j < i - 1; j++)
            dp[i] = (dp[i] + dp[j] * dp[i - j - 2]) % MOD;
    }
    while (T--)
    {
        std::cin >> E;
        std::cout << dp[E] << '\n';
    }
}