#include <iostream>
#include <string>
#include <string.h>

int T, N;
int dp[12];

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> T;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    for (int i = 4; i <= 11; i++)
        dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
    while (T--)
    {
        std::cin >> N;
        std::cout << dp[N] << '\n';
    }
}