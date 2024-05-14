#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>

int N;
int a[100001];
int b[100001];
long long dp[100001][2];
const int MOD = 1e9 + 7;

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N;
    for (int i = 1; i <= N; i++)
        std::cin >> a[i];
    for (int i = 1; i <= N - 1; i++)
        std::cin >> b[i];
    dp[0][0] = 1;
    for (int i = 1; i <= N; i++)
    {
        dp[i][0] = (dp[i - 1][0] * (a[i] + b[i - 1])
                + dp[i - 1][1] * (a[i] + b[i - 1] - 1)) % MOD;
        dp[i][1] = (dp[i - 1][0] + dp[i - 1][1]) * b[i] % MOD;
    }
    std::cout << dp[N][0] << '\n';
}
