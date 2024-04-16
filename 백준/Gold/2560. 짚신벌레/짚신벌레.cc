#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

int a, b, d, N;
const int MOD = 1000;
int dp[1000001];

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> a >> b >> d >> N;
    dp[0] = 1;
    for (int i = 1; i <= N; i++)
    {
        dp[i] = dp[i - 1];
        if (i >= a)
            dp[i] = (dp[i] + dp[i - a]) % MOD;
        if (i >= b)
            dp[i] = (dp[i] - dp[i - b] + MOD) % MOD;
    }
    std::cout << (dp[N] - dp[N - d] + MOD) % MOD << '\n';
}