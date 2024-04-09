#include <iostream>
#include <vector>

int N;
int arr[1500001][2];
int dp[1500001];

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N;
    for (int i = 0; i < N; i++)
        std::cin >> arr[i][0] >> arr[i][1];
    for (int i = 0; i < N; i++)
    {
        if (i + arr[i][0] <= N)
            dp[i + arr[i][0]] = std::max(dp[i + arr[i][0]], dp[i] + arr[i][1]);
        dp[i + 1] = std::max(dp[i + 1], dp[i]);
    }
    std::cout << dp[N] << '\n';
}