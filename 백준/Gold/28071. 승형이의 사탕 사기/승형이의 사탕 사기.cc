#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#include <cmath>

int N, M, K;
int arr[301];
int dp[301][301][301];

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N >> M >> K;
    for (int i = 1; i <= N; i++)
        std::cin >> arr[i];
    memset(dp, -1, sizeof(dp));
    dp[0][0][0] = 0;
    for (int i = 1; i <= N; i++)
    {
        dp[i][0][0] = 0;
        for (int j = 1; j <= M; j++)
        {
            for (int k = 0; k < K; k++)
            {
                int next_k = (k + arr[i]) % K;
                if (dp[i - 1][j - 1][k] != -1)
                    dp[i][j][next_k] = std::max(dp[i][j][next_k], dp[i - 1][j - 1][k] + arr[i]);
                if (dp[i - 1][j][k] != -1)
                    dp[i][j][k] = std::max(dp[i][j][k], dp[i - 1][j][k]);
                if (dp[i][j - 1][k] != -1)
                    dp[i][j][next_k] = std::max(dp[i][j][next_k], dp[i][j - 1][k] + arr[i]);
            }
        }
    }
    int ans = 0;
    for (int i = 0; i <= M; i++)
        ans = std::max(ans, dp[N][i][0]);
    std::cout << ans << '\n';
}