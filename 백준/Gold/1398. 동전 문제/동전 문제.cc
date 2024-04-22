#include <iostream>
#include <map>

int T;
int dp[101];

long long solve(long long n)
{
    long long ret = 0;
    while (n >= 100)
    {
        long long tmp = n % 100;
        n /= 100;
        ret += dp[tmp];
    }
    return ret + dp[n];
}

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> T;
    std::fill(dp, dp + 100, 1e9);
    dp[0] = 0;
    dp[1] = 1;
    dp[10] = 1;
    dp[25] = 1;
    for (int i = 2; i <= 100; i++)
    {
        dp[i] = std::min(dp[i - 1] + 1, dp[i]);
        if (i >= 10)
            dp[i] = std::min(dp[i - 10] + 1, dp[i]);
        if (i >= 25)
            dp[i] = std::min(dp[i - 25] + 1, dp[i]);
    }
    while (T--)
    {
        long long N;
        std::cin >> N;
        std::cout << solve(N) << '\n';
    }
}