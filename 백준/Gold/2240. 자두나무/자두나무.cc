#include <iostream>
#include <queue>
#include <vector>

int T, W;
int arr[1010];
int dp[1010][31][2];

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> T >> W;
    for (int i = 0; i < T; i++)
    {
        std::cin >> arr[i];
        arr[i]--;
    }
    dp[0][0][0] = (arr[0] == 0);
    dp[0][1][1] = (arr[0] == 1);
    for (int i = 1; i < T; i++)
    {
        for (int j = 0; j <= W; j++)
        {
            if (j > 0)
            {
                dp[i][j][0] = std::max(dp[i - 1][j][0], dp[i - 1][j - 1][1]) + (arr[i] == 0);
                dp[i][j][1] = std::max(dp[i - 1][j][1], dp[i - 1][j - 1][0]) + (arr[i] == 1);
            }
            else
            {
                dp[i][j][0] = dp[i - 1][j][0] + (arr[i] == 0);
                dp[i][j][1] = dp[i - 1][j][1] + (arr[i] == 1);
            }
        }
    }
    int max = 0;
    for (int i = 0; i <= W; i++)
    {
        max = std::max(max, dp[T - 1][i][0]);
        max = std::max(max, dp[T - 1][i][1]);
    }
    std::cout << max << '\n';
}