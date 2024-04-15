#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

int T;

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> T;
    while (T--)
    {
        int N;
        std::vector<int> coin;
        std::cin >> N;
        for (int i = 0; i < N; ++i)
        {
            int tmp;
            std::cin >> tmp;
            coin.push_back(tmp);
        }
        int M;
        std::cin >> M;
        std::vector<int> dp(M + 1, 0);
        dp[0] = 1;
        for (int i = 0; i < N; ++i)
        {
            for (int j = coin[i]; j <= M; ++j)
            {
                dp[j] += dp[j - coin[i]];
            }
        }
        std::cout << dp[M] << '\n';
    }
}