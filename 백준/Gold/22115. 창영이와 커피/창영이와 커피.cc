#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

int N, K;
int arr[101];
int dp[101][100001];

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N >> K;
    for (int i = 1; i <= N; i++)
        std::cin >> arr[i];
    for (int i = 1; i <= K; i++)
        dp[0][i] = 1e9;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= K; j++)
        {
            if (j - arr[i] >= 0)
                dp[i][j] = std::min(dp[i - 1][j], dp[i - 1][j - arr[i]] + 1);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    if (dp[N][K] == 1e9)
        std::cout << -1 << '\n';
    else
        std::cout << dp[N][K] << '\n';
}