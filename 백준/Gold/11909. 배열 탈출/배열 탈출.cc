#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <climits>

int N;
int map[2223][2223];
int dp[2223][2223];
int d[2][2] = {{1, 0}, {0, 1}};

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N;
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            std::cin >> map[i][j];
    std::fill(&dp[0][0], &dp[N + 1][N + 1], INT_MAX);
    dp[1][1] = 0;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            for (int k = 0; k < 2; k++)
            {
                int x = i + d[k][0];
                int y = j + d[k][1];
                if (map[i][j] <= map[x][y])
                    dp[x][y] = std::min(dp[x][y], dp[i][j] + map[x][y] - map[i][j] + 1);
                else
                    dp[x][y] = std::min(dp[x][y], dp[i][j]);
            }
        }
    }
    std::cout << dp[N][N] << '\n';
}