#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

int N, M;
int arr[50001];
int dp[4][50001];

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N;
    for (int i = 1; i <= N; i++)
    {
        std::cin >> arr[i];
        arr[i] += arr[i - 1];
    }
    std::cin >> M;
    for (int i = 1; i <= 3; i++)
    {
        for (int j = i * M; j <= N; j++)
        {
            dp[i][j] = std::max(dp[i][j - 1], dp[i - 1][j - M] + arr[j] - arr[j - M]);
        }
    }
    std::cout << dp[3][N] << '\n';
}