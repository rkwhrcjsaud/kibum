#include <iostream>
#include <queue>
#include <vector>

int N;
int arr[1000001];
int dp[1000001][2];

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N;
    for (int i = 0; i < N; i++)
        std::cin >> arr[i];
    dp[0][0] = arr[0];
    dp[0][1] = 0;
    for (int i = 1; i < N; i++)
    {
        dp[i][0] = std::max(dp[i - 1][0] + arr[i], arr[i]);
        dp[i][1] = std::max(dp[i - 1][0], dp[i - 1][1] + arr[i]);
    }
    int max = 0;
    for (int i = 0; i < N; i++)
    {
        max = std::max(max, dp[i][0]);
        max = std::max(max, dp[i][1]);
    }
    if (max == 0)
    {
        max = arr[0];
        for (int i = 1; i < N; i++)
            max = std::max(max, arr[i]);
    }
    std::cout << max << '\n';
}