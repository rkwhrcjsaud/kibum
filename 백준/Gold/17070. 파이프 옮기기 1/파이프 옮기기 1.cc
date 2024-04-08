#include <iostream>

int N;
int map[16][16];
int dp[16][16][3];

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            std::cin >> map[i][j];
    }
    dp[0][1][0] = 1;
    for (int i = 0; i < N; i++)
    {
        for (int j = 2; j < N; j++)
        {
            if (map[i][j] == 0)
            {
                if (j > 0)
                    dp[i][j][0] = dp[i][j - 1][0] + dp[i][j - 1][2];
                if (i > 0)
                    dp[i][j][1] = dp[i - 1][j][1] + dp[i - 1][j][2];
                if (i > 0 && j > 0 && map[i - 1][j] == 0 && map[i][j - 1] == 0)
                    dp[i][j][2] = dp[i - 1][j - 1][0] + dp[i - 1][j - 1][1] + dp[i - 1][j - 1][2];
            }
        }
    }
    std::cout << dp[N - 1][N - 1][0] + dp[N - 1][N - 1][1] + dp[N - 1][N - 1][2] << '\n';
}