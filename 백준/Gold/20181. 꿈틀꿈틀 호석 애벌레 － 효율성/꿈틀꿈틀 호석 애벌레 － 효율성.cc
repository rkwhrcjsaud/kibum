#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

typedef long long ll;
ll N, K, sum;
ll arr[100001];
ll dp[100001];

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N >> K;
    for (int i = 1; i <= N; i++)
        std::cin >> arr[i];
    for (int r = 1, l = 0; r <= N; r++)
    {
        sum += arr[r];
        dp[r] = dp[r - 1];
        while (sum >= K)
        {
            dp[r] = std::max(dp[r], dp[l] + sum - K);
            sum -= arr[++l];
        }
    }
    std::cout << dp[N] << '\n';
}