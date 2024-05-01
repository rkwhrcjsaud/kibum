#include <iostream>
#include <vector>
#include <algorithm>

int T, N;
long long dp[21];

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> T;
    dp[1] = 0;
    dp[2] = 1;
    for (int i = 3; i <= 20; i++)
        dp[i] = (dp[i - 1] + dp[i - 2]) * (i - 1);
    while (T--)
    {
        std::cin >> N;
        std::cout << dp[N] << '\n';
    }
}