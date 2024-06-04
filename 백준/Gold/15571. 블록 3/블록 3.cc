#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

int N, M;
long long dp[1000001];
const int MOD = 1999;
long long t;

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N >> M;
    dp[1] = 1;
    for (int i = 2; i <= N; i++)
    {
        dp[i] = dp[i - 1] * 2;
        dp[i] %= MOD;
    }
    t = dp[N];
    dp[N] = (dp[N] * 2 - 1);
    dp[N] %= MOD;
    int sum = 0;
    for (int i = 1; i <= N; i++)
    {
        sum += dp[i];
        sum %= MOD;
    }
    sum += t - 1;
    sum %= MOD;
    for (int i = N + 1; i <= M; i++)
    {
        dp[i] = sum;
        sum += 1999 * t;
        sum -= dp[i - N] * t;
        sum += dp[i];
        sum += (t - 1) * dp[i - N + 1];
        sum %= MOD;
    }
    std::cout << dp[M] << '\n';
}
