#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

int T, H, C;
int arr[201];
double dp[201][201];
double dp2[201][201];

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> T;
    std::cout << std::fixed;
    std::cout.precision(4);
    while (T--)
    {
        std::cin >> H >> C;
        memset(arr, 0, sizeof(arr));
        for (int i = 0; i < H; i++)
            std::cin >> arr[i];
        for (int i = 0; i < H - 2; i++)
        {
            for (int j = i + 2; j < H; j++)
            {
                double sum = 0;
                for (int k = i + 1; k < j; k++)
                    sum += std::abs(arr[k] - (arr[i] + (arr[j] - arr[i]) * ((double)k - i) / ((double)j - i)));
                dp[i][j] = sum / H;
            }
        }
        for (int i = 0; i < H; i++)
            for (int j = 0; j <= C; j++)
                dp2[i][j] = (i == 0) ? 0 : 1e9;
        for (int i = 1; i < H; i++)
        {
            for (int j = 2; j <= C; j++)
            {
                for (int k = 0; k < i; k++)
                {
                    dp2[i][j] = std::min(dp2[i][j], dp[k][i] + dp2[k][j - 1]);
                }
            }
        }
        std::cout << dp2[H - 1][C] << '\n';
    }
}