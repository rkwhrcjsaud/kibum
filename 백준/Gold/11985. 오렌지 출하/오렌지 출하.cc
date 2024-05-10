#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

typedef long long ll;
ll N, M, K;
ll arr[20002];
ll dp[20002];

ll solve()
{
    for (ll i = 1; i <= N; i++)
    {
        dp[i] = 1e18;
        ll max = arr[i], min = arr[i];
        for (ll j = i; j >= std::max(1LL, i - M + 1); j--)
        {
            max = std::max(max, arr[j]);
            min = std::min(min, arr[j]);
            dp[i] = std::min(dp[i], dp[j - 1] + K + (i - j + 1) * (max - min));
        }
    }
    return dp[N];
}

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N >> M >> K;
    for (int i = 1; i <= N; i++)
        std::cin >> arr[i];
    std::cout << solve() << '\n';
}