#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

int N;
long long dp[101];

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N;
    for (int i = 1; i <= 6; i++)
        dp[i] = i;
    for (int i = 7; i <= N; i++)
    {
        for (int j = 3; j < i; j++)
            dp[i] = std::max(dp[i], dp[i - j] * (j - 1));
    }
    std::cout << dp[N] << '\n';
}