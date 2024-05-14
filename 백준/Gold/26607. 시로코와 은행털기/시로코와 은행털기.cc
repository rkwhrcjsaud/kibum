#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>

int N, K, X;
int a[81];
bool dp[81][16001];

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N >> K >> X;
    for (int i = 0; i < N; i++)
    {
        int tmp;
        std::cin >> a[i] >> tmp;
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = K - 1; j >= 1; j--)
            for (int k = X * K; k >= a[i]; k--)
                dp[j + 1][k] = dp[j + 1][k] || dp[j][k - a[i]];
        dp[1][a[i]] = true;
    }
    int ans = 0;
    for (int i = 0; i <= X * K; i++)
    {
        if (dp[K][i])
            ans = std::max(ans, i * (X * K - i));
    }
    std::cout << ans << '\n';
}
