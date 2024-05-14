#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>

int N, T;
int point[201][2];
int dist[201][201];
int dp[1001][201]; // dp[i][j] = i분에 j번째 지점에 있을 때 최대 경험치

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N >> T;
    memset(dp, -1, sizeof(dp));
    for (int i = 0; i < N; i++)
    {
        std::cin >> point[i][0] >> point[i][1];
        if (point[i][0] == 0)
            dp[0][i] = 0;
    }
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            std::cin >> dist[i][j];
    for (int i = 1; i <= T; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (dp[i - 1][j] != -1)
            {
                dp[i][j] = std::max(dp[i][j], dp[i - 1][j] + point[j][1]);
            }
            for (int k = 0; k < N; k++)
            {
                int prev = i - dist[j][k];
                if (prev < 0 || j == k)
                    continue;
                if (dp[prev][k] != -1 && dp[prev][k] >= point[j][0])
                    dp[i][j] = std::max(dp[i][j], dp[prev][k]);
            }
        }
    }
    int result = 0;
    for (int i = 0; i < N; i++)
        result = std::max(result, dp[T][i]);
    std::cout << result << '\n';
}
