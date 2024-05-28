#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <map>

int N;
int t[100001];
int b[100001];
int c[100001];
long long dp[100001];

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N;
    for (int i = 0; i < N; i++)
        std::cin >> t[i];
    for (int i = 0; i < N; i++)
        std::cin >> b[i];
    for (int i = 0; i < N; i++)
        std::cin >> c[i];
    dp[0] = c[0];
    for (int i = 1; i < N; i++)
    {
        int idx = std::lower_bound(t, t + i + 1, t[i] - b[i]) - t;
        dp[i] = std::max(dp[i - 1], (long long)c[i]);
        if (--idx >= 0)
            dp[i] = std::max(dp[i], dp[idx] + c[i]);
    }
    std::cout << dp[N - 1] << '\n';
}