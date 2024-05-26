#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

int N, M;
int dp[100001];
const int MOD = 1999;
int t;

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
    for (int i = N + 1; i <= M; i++)
    {
        dp[i] = dp[i - N] * t;
        dp[i] %= MOD;
        for (int j = 1; j < N; j++)
        {
            dp[i] += dp[i - j];
            dp[i] %= MOD;
        }
    }
    std::cout << dp[M] << '\n';
}