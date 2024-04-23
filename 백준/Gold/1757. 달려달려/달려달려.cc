#include <iostream>
#include <queue>
#include <vector>
#include <sstream>
#include <cstring>
#include <climits>

int N, M;
int arr[10001];
int dp[10001][501];

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N >> M;
    for (int i = 1; i <= N; i++)
        std::cin >> arr[i];
    for (int i = 1; i <= N; i++)
    {
        dp[i][0] = dp[i - 1][0];
        for (int j = 1; j <= M; j++)
        {
            dp[i][j] = dp[i - 1][j - 1] + arr[i];
            if (i >= j)
                dp[i][0] = std::max(dp[i][0], dp[i - j][j]);
        }
    }
    std::cout << dp[N][0] << '\n';
}