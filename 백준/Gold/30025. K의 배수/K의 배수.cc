#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <sstream>
#include <map>
#include <queue>

int N, M, K;
int arr[11];
int dp[101][1001];
int MOD = 1e9 + 7;

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N >> M >> K;
    for (int i = 0; i < N; i++)
    {
        std::cin >> arr[i];
        if (arr[i])
            dp[1][arr[i] % K]++;
    }
    for (int i = 2; i <= M; i++)
    {
        for (int j = 0; j < K; j++)
        {
            for (int k = 0; k < N; k++)
            {
                dp[i][(j * 10 + arr[k]) % K] += dp[i - 1][j];
                dp[i][(j * 10 + arr[k]) % K] %= MOD;
            }
        }
    }
    std::cout << dp[M][0] << '\n';
}