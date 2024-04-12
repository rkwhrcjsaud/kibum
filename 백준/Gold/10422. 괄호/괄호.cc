#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

int T;
long long dp[5001];

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> T;
    while (T--)
    {
        int N;
        std::cin >> N;
        if (N % 2)
        {
            std::cout << "0\n";
            continue;
        }
        std::fill(dp, dp + 5001, 0);
        dp[0] = 1;
        for (int i = 2; i <= N; i += 2)
        {
            for (int j = 2; j <= i; j += 2)
            {
                dp[i] += dp[j - 2] * dp[i - j];
                dp[i] %= 1000000007;
            }
        }
        std::cout << dp[N] << '\n';
    }
}