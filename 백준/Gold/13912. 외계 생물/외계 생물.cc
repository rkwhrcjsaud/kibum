#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <map>

int H;
typedef long long ll;
const int MOD = 1e9 + 7;
ll dp[2049][2049];

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> H;
    for (int i = 0; i < 2049; i++)
        dp[i][0] = 1;
    dp[1][1] = 1;
    dp[2][1] = 2;
    dp[2][2] = 1;
    for (int i = 3; i < 2049; i++)
        for (int j = 1; j <= i; j++)
            dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - 1]) % MOD;
    ll ans = 1;
    for (int i = 0; i <= H; i++)
    {
        for (int j = 0; j < (1 << i); j++)
        {
            ans *= dp[(1 << (H + 1 - i)) - 2][(1 << (H - i)) - 1];
            ans %= MOD;
        }
    }
    std::cout << ans << '\n';
}