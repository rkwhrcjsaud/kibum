#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

int M, N;
int map[1001][1001];
int dp[1001][1001];

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> M >> N;
    for (int i = 1; i <= M; i++)
        for (int j = 1; j <= N; j++)
            std::cin >> map[i][j];
    int max = 0;
    for (int i = 1; i <= M; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            int min = std::min(dp[i - 1][j - 1],
                std::min(dp[i - 1][j], dp[i][j - 1]));
            dp[i][j] = map[i][j] ? 0 : min + 1;
            max = std::max(max, dp[i][j]);
        }
    }
    std::cout << max << '\n';
}