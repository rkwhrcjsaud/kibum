#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <sstream>

int D, N;
int t[201];
int a[201], b[201], c[201];
int dp[201][101];

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> D >> N;
    for (int i = 1; i <= D; i++)
        std::cin >> t[i];
    for (int i = 1; i <= N; i++)
        std::cin >> a[i] >> b[i] >> c[i];
    memset(dp, -1, sizeof(dp));
    for (int i = 1; i <= N; i++)
    {
        if (a[i] > t[1] || b[i] < t[1])
            continue;
        dp[1][c[i]] = 0;
    }
    for (int i = 2; i <= D; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            if (a[j] > t[i] || b[j] < t[i])
                continue;
            for (int k = 0; k <= 100; k++)
            {
                if (dp[i - 1][k] == -1)
                    continue;
                dp[i][c[j]] = std::max(dp[i][c[j]], dp[i - 1][k] + abs(k - c[j]));
            }
        }
    }
    int ans = 0;
    for (int i = 0; i <= 100; i++)
        ans = std::max(ans, dp[D][i]);
    std::cout << ans << '\n';
    
}