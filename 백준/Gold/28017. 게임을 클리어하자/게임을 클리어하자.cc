#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

int N, M;
int arr[501][501];
int dp[501][501];

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N >> M;
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++)
            std::cin >> arr[i][j];
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            dp[i][j] = 1e9;
            for (int k = 1; k <= M; k++)
            {
                if (k == j)
                    continue;
                dp[i][j] = std::min(dp[i][j], dp[i - 1][k] + arr[i][j]);
            }
        }
    }
    int ans = 1e9;
    for (int i = 1; i <= M; i++)
        ans = std::min(ans, dp[N][i]);
    std::cout << ans << '\n';
}