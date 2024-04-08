#include <iostream>

int N, M;
int dp[1001][1001];

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N >> M;
    for (int i = 1; i <= N; i++)
    {
        std::string str;
        std::cin >> str;
        for (int j = 1; j <= M; j++)
            dp[i][j] = str[j - 1] - '0';
    }
    int max = 0;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            if (dp[i][j] == 1)
            {
                dp[i][j] = std::min(dp[i - 1][j], std::min(dp[i][j - 1], dp[i - 1][j - 1])) + 1;
                max = std::max(max, dp[i][j]);
            }
        }
    }
    std::cout << max * max << '\n';
}