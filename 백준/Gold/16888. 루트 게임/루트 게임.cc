#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>

int T, N;
bool dp[1000001];

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> T;
    dp[1] = true;
    dp[2] = false;
    for (int i = 1; i <= 1000; i++)
        dp[i * i] = true;
    for (int i = 2; i <= 1000000; i++)
        if (!dp[i])
            for (int j = 1; j * j + i <= 1000000; j++)
                dp[j * j + i] = true;
    while (T--)
    {
        std::cin >> N;
        std::cout << (dp[N] ? "koosaga" : "cubelover") << '\n';
    }
}
