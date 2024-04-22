#include <iostream>
#include <vector>
#include <algorithm>

int N, M;
int dp[1001][1001];

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    while (1)
    {
        std::cin >> N >> M;
        if (N == 0 && M == 0)
            break;
        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= M; j++)
            {
                char tmp;
                std::cin >> tmp;
                if (tmp == '1')
                    dp[i][j] = std::min(dp[i - 1][j], std::min(dp[i][j - 1], dp[i - 1][j - 1])) + 1;
            }
        }
        int result = 0;
        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= M; j++)
            {
                result = std::max(result, dp[i][j]);
            }
        }
        std::cout << result << '\n';
        std::fill(&dp[0][0], &dp[1000][1001], 0);
    }
}