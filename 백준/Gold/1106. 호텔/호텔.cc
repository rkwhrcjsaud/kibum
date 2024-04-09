#include <iostream>
#include <queue>
#include <vector>

int C, N;
const int INF = 1000000;
int dp[1200];

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> C >> N;
    for (int i = 0; i < 1200; i++)
        dp[i] = INF;
    int result = INF;
    dp[0] = 0;
    for (int i = 0; i < N; i++)
    {
        int a, b;
        std::cin >> a >> b;
        for (int j = b; j < 1200; j++)
        {
            dp[j] = std::min(dp[j - b] + a, dp[j]);
            if (j >= C)
                result = std::min(result, dp[j]);
        }
    }
    std::cout << result << '\n';
}