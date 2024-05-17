#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <sstream>

int N, K;
int button[101][2];
int dp[101][5001]; // dp[i][j] = i초일 때 speed가 j인 경우의 최대 점수

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N >> K;
    for (int i = 0; i < N; i++)
        std::cin >> button[i][0] >> button[i][1];
    memset(dp, -1, sizeof(dp));
    dp[0][1] = 0;
    for (int i = 1; i <= K; i++)
    {
        for (int j = 0; j <= 5000; j++)
        {
            if (dp[i - 1][j] != -1)
                dp[i][j] = std::max(dp[i][j], dp[i - 1][j] + j);
            for (int k = 0; k < N; k++)
            {
                if (j > button[k][1] && dp[i - 1][j - button[k][1]] >= button[k][0] && dp[i - 1][j - button[k][1]] != -1)
                {
                    dp[i][j] = std::max(dp[i][j], dp[i - 1][j - button[k][1]] - button[k][0]);
                }
            }
        }
    }
    int ans = 0;
    for (int i = 0; i <= 5000; i++)
        ans = std::max(ans, dp[K][i]);
    std::cout << ans << '\n';
}