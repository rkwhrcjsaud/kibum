#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <sstream>
#include <map>

int N;
int arr[100001];
int dp[100001][2][2][2];

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N;
    for (int i = 0; i < N; i++)
        std::cin >> arr[i];
    dp[0][0][0][0] = dp[0][0][0][1] = arr[0];
    dp[0][0][1][0] = dp[0][0][1][1] = arr[0];
    for (int i = 1; i < N; i++)
    {
        dp[i][0][0][0] = std::max(dp[i - 1][0][0][0] + arr[i], arr[i]);
        dp[i][0][0][1] = std::max(dp[i - 1][0][0][1], dp[i][0][0][0]);
        dp[i][0][1][0] = std::min(dp[i - 1][0][1][0] + arr[i], arr[i]);
        dp[i][0][1][1] = std::min(dp[i - 1][0][1][1], dp[i][0][1][0]);
    }
    dp[N - 1][1][0][0] = dp[N - 1][1][0][1] = arr[N - 1];
    dp[N - 1][1][1][0] = dp[N - 1][1][1][1] = arr[N - 1];
    for (int i = N - 2; i >= 0; i--)
    {
        dp[i][1][0][0] = std::max(dp[i + 1][1][0][0] + arr[i], arr[i]);
        dp[i][1][0][1] = std::max(dp[i + 1][1][0][1], dp[i][1][0][0]);
        dp[i][1][1][0] = std::min(dp[i + 1][1][1][0] + arr[i], arr[i]);
        dp[i][1][1][1] = std::min(dp[i + 1][1][1][1], dp[i][1][1][0]);
    }
    long long ans = -1e9;
    for (int i = 0; i < N - 1; i++)
    {
        ans = std::max(ans, (long long)dp[i][0][0][1] * dp[i + 1][1][0][1]);
        ans = std::max(ans, (long long)dp[i][0][1][1] * dp[i + 1][1][1][1]);
    }
    std::cout << ans << '\n';
}