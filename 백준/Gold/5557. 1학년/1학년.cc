#include <iostream>
#include <vector>

int N;
int arr[101];
long long dp[101][21];

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N;
    for (int i = 0; i < N; i++)
        std::cin >> arr[i];
    dp[0][arr[0]] = 1;
    for (int i = 1; i < N - 1; i++)
    {
        for (int j = 0; j <= 20; j++)
        {
            if (j - arr[i] >= 0)
                dp[i][j] += dp[i - 1][j - arr[i]];
            if (j + arr[i] <= 20)
                dp[i][j] += dp[i - 1][j + arr[i]];
        }
    }
    std::cout << dp[N - 2][arr[N - 1]] << '\n';
}