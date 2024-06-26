#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <sstream>
#include <map>
#include <queue>
#include <cmath>

typedef long long ll;
int N, M;
ll port[301];
ll cost[301];
ll dp[100001];

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N;
    for (int i = 0; i < N; i++)
        std::cin >> port[i] >> cost[i];
    std::cin >> M;
    if (M == 1)
    {
        std::cout << 0 << '\n';
        return 0;
    }
    for (int i = 0; i <= M; i++)
        dp[i] = 1e18;
    dp[0] = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 100000; j >= port[i]; j--)
            dp[j] = std::min(dp[j], dp[j - port[i] + 2] + cost[i]);
        dp[port[i] - 1] = std::min(dp[port[i] - 1], cost[i]);
    }
    std::cout << (dp[M] == 1e18 ? -1 : dp[M]) << '\n';
}