#include <iostream>
#include <vector>

int N, K;
int dp[10001];
std::vector<int> v;

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::fill(dp, dp + 10001, -1);
    dp[0] = 0;
    std::cin >> N >> K;
    for (int i = 0; i < N; i++)
    {
        int tmp;
        std::cin >> tmp;
        v.push_back(tmp);
    }
    for (int i = 1; i <= K; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (i - v[j] >= 0 && dp[i - v[j]] != -1)
            {
                if (dp[i] == -1)
                    dp[i] = dp[i - v[j]] + 1;
                else
                    dp[i] = std::min(dp[i], dp[i - v[j]] + 1);
            }
        }
    }
    std::cout << dp[K] << '\n';
}