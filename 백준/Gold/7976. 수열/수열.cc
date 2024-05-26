#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

int N, K;
int cnt[1000001][2];
int dp[1000001][2];

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N >> K;
    for (int i = 0; i < N; i++)
    {
        int num;
        std::cin >> num;
        cnt[i % K][num & 1]++;
    }
    dp[0][0] = cnt[0][1];
    dp[0][1] = cnt[0][0];
    for (int i = 1; i < K; i++)
    {
        dp[i][0] = std::min(dp[i - 1][1] + cnt[i][0], dp[i - 1][0] + cnt[i][1]);
        dp[i][1] = std::min(dp[i - 1][0] + cnt[i][0], dp[i - 1][1] + cnt[i][1]);
    }
    std::cout << dp[K - 1][0] << '\n';
}
