#include <iostream>
#include <queue>
#include <vector>
#include <sstream>
#include <cstring>
#include <climits>

int N, M;
int arr[100001];
int sum[100001];
int dp[100001][2];

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N >> M;
    for (int i = 1; i <= N; i++)
    {
        std::cin >> arr[i];
        sum[i] = sum[i - 1] + arr[i];
    }
    dp[M][1] = sum[M];
    for (int i = M + 1; i <= N; i++)
    {
        dp[i][0] = std::max(dp[i - 1][0], dp[i - 1][1]);
        dp[i][1] = std::max(dp[i - 1][1] + arr[i], sum[i] - sum[i - M]);
    }
    std::cout << std::max(dp[N][0], std::max(dp[N][1], 0)) << '\n';
}