#include <iostream>
#include <vector>
#include <algorithm>

int N, M;
int map[201][201];
int dp[201][201];

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N >> M;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            std::cin >> map[i][j];
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + map[i][j];
        }
    }
    int result = -5e8;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            for (int k = 1; k <= i; k++)
            {
                for (int l = 1; l <= j; l++)
                {
                    result = std::max(result, dp[i][j] - dp[k - 1][j] - dp[i][l - 1] + dp[k - 1][l - 1]);
                }
            }
        }
    }
    std::cout << result << '\n';
}