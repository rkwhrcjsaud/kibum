#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <sstream>
#include <map>
#include <queue>
#include <cmath>

int N;
int dp[1000001][2];
int MOD = 9901;

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N;
    dp[1][0] = 1;
    for (int i = 2; i <= N; i++)
        dp[i][0] = (dp[i - 1][0] * 2 + 1) % MOD;
    dp[1][1] = 1;
    dp[2][1] = 3;
    dp[3][1] = 5;
    for (int i = 4; i <= N; i++)
    {
        double k = i - std::sqrt(i * 2 + 1) + 1;
        int t = (int)(k + 0.5);
        dp[i][1] = (dp[t][1] * 2 + dp[i - t][0]) % MOD;
    }
    std::cout << dp[N][1] << '\n';
}