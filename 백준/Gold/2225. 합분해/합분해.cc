#include <iostream>

int N, K;
int dp[201][201];
int mod = 1000000000;

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N >> K;
    for (int i = 0; i <= N; i++)
        dp[i][1] = 1;
    for (int i = 1; i <= K; i++)
        dp[0][i] = 1;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 2; j <= K; j++)
            dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % mod;
    }
    std::cout << dp[N][K] << '\n';    
}