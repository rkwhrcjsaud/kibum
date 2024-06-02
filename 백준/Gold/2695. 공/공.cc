#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#include <cmath>

int P, B, M;
int dp[51][1001];

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> P;
    for (int i = 1; i <= 1000; i++)
        dp[1][i] = i;
    for (int i = 2; i <= 50; i++)
    {
        for (int j = 1; j <= 1000; j++)
        {
            dp[i][j] = 1e9;
            for (int k = 1; k <= j; k++)
            {
                dp[i][j] = std::min(dp[i][j], std::max(dp[i - 1][k - 1], dp[i][j - k]) + 1);
            }
        }
    }
    while (P--)
    {
        std::cin >> B >> M;
        std::cout << dp[B][M] << '\n';
    }
}