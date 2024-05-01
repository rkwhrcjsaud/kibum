#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

int N;
int dp[700000];

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N;
    dp[1] = 1;
    int num = dp[1];
    int i = 1;
    for (; num < N; i++)
    {
        dp[i + 1] = 1 + dp[i + 1 - dp[dp[i]]];
        num += dp[i + 1];
    }
    std::cout << i << '\n';
}
