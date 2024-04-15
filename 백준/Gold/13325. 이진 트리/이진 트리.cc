#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

int K;
std::vector<int> dp[21];

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> K;
    int ans = 0;
    dp[0].push_back(0);
    for (int level = 1; level <= K; level++)
    {
        for (int i = 0; i < (1 << level); i++)
        {
            int num;
            std::cin >> num;
            dp[level].push_back(num);
            ans += num;
        }
    }
    for (int level = K; level >= 1; level--)
    {
        for (int i = 0; i < (1 << level); i += 2)
        {
            dp[level - 1][i / 2] += std::max(dp[level][i], dp[level][i + 1]);
            ans += std::abs(dp[level][i] - dp[level][i + 1]);
        }
    }
    std::cout << ans << '\n';
}