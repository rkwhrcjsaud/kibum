#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#include <cmath>

int W, H, N;
int dp[601][601];

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> W >> H >> N;
    for (int i = 1; i <= W; i++)
        for (int j = 1; j <= H; j++)
            dp[i][j] = i * j;
    for (int i = 0; i < N; i++)
    {
        int x, y;
        std::cin >> x >> y;
        dp[x][y] = 0;
    }
    for (int i = 1; i <= W; i++)
    {
        for (int j = 1; j <= H; j++)
        {
            for (int k = 1; k <= i - k; k++)
                dp[i][j] = std::min(dp[i][j], dp[k][j] + dp[i - k][j]);
            for (int k = 1; k <= j - k; k++)
                dp[i][j] = std::min(dp[i][j], dp[i][k] + dp[i][j - k]);
        }
    }
    std::cout << dp[W][H] << '\n';
}