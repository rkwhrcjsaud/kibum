#include <iostream>
#include <queue>
#include <vector>

int T;
int dp[10001][3];

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> T;
    dp[1][0] = 1;
    dp[2][0] = 1;
    dp[2][1] = 1;
    dp[3][0] = 1;
    dp[3][1] = 1;
    dp[3][2] = 1;
    for (int i = 4; i <= 10000; i++)
    {
        dp[i][0] = dp[i - 1][0];
        dp[i][1] = dp[i - 2][0] + dp[i - 2][1];
        dp[i][2] = dp[i - 3][0] + dp[i - 3][1] + dp[i - 3][2];
    }
    while (T--)
    {
        int N;
        std::cin >> N;
        std::cout << dp[N][0] + dp[N][1] + dp[N][2] << '\n';
    }
}