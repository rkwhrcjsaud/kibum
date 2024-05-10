#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

int T, N, M;
int point[11];
int dp[5001][5001];
// dp[i][j] = i개의 팔굽혀펴기를 하고 누적득점이 j일 때 최대 점수

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> T;
    while (T--)
    {
        std::cin >> N >> M;
        memset(dp, -1, sizeof(dp));
        for (int i = 0; i < M; i++)
            std::cin >> point[i];
        dp[0][0] = 0;
        for (int i = 0; i <= N; i++)
        {
            for (int j = 0; j <= i; j++)
            {
                if (dp[i][j] == -1)
                    continue;
                for (int k = 0; k < M; k++)
                {
                    if (i + j + point[k] > N)
                        continue;
                    dp[i + j + point[k]][j + point[k]] = std::max(dp[i + j + point[k]][j + point[k]], dp[i][j] + point[k]);
                }
            }
        }
        int ans = -1;
        for (int i = 0; i <= N; i++)
            ans = std::max(ans, dp[N][i]);
        std::cout << ans << '\n';
    }
}