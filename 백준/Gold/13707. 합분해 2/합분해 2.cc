#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

int N, K;
int dp[5001][5001];
const int MOD = 1e9;

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N >> K;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= K; j++)
        {
            if (i == 1)
            {
                dp[i][j] = j;
                continue ;
            }
            if (j == 1)
            {
                dp[i][j] = 1;
                continue ;
            }
            dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % MOD;
        }
    }
    std::cout << dp[N][K] << '\n';
}
