#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#include <cmath>

typedef long long ll;
ll C, E, D, N;
ll dist[1010];
ll price[1010];
ll dp[1010][501];
ll ans;

ll solve(int idx, int fuel)
{
    if (idx == N + 1)
        return 0;
    ll &ret = dp[idx][fuel];
    if (ret != -1)
        return ret;
    ret = 1e18;
    if (C < E * (dist[idx + 1] - dist[idx]))
        return ret;
    ret = std::min(ret, solve(idx + 1, C - E * (dist[idx + 1] - dist[idx])) + price[idx] * (C - fuel));
    for (int i = idx + 1; i <= N + 1; i++)
    {
        int used = (dist[i] - dist[idx]) * E;
        if (C < used)
            break ;
        if (fuel >= used)
            ret = std::min(ret, solve(i, fuel - used));
        else
            ret = std::min(ret, solve(i, 0) + (used - fuel) * price[idx]);
    }
    return ret;
}

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> C >> E >> D >> N;
    if (N == 0)
    {
        if (D * E <= C)
            std::cout << 0;
        else
            std::cout << -1;
        std::cout << '\n';
        return 0;
    }
    for (int i = 1; i <= N; i++)
    {
        std::cin >> dist[i];
        dist[i] += dist[i - 1];
    }
    dist[N + 1] = D;
    for (int i = 1; i <= N; i++)
        std::cin >> price[i];
    memset(dp, -1, sizeof(dp));
    ans = solve(0, C);
    if (ans >= 1e18)
        std::cout << -1;
    else
        std::cout << ans;
    std::cout << '\n';
}