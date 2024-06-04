#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

int N;
typedef long long ll;
ll w[1001];
ll e[1001];
ll dp[1001];

ll solve(int idx)
{
    if (idx == N)
        return 0;
    ll &ret = dp[idx];
    if (ret != -1)
        return ret;
    ret = (ll)1e18;
    ret = std::min(ret, solve(idx + 1) + w[idx] * e[idx]);
    ll wmax = w[idx], emax = e[idx];
    for (int i = idx + 1; i < N; i++)
    {
        wmax = std::max(wmax, w[i]);
        emax = std::max(emax, e[i]);
        ret = std::min(ret, solve(i + 1) + wmax * emax);
    }
    return ret;
}

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N;
    for (int i = 0; i < N; i++)
        std::cin >> w[i];
    for (int i = 0; i < N; i++)
        std::cin >> e[i];
    for (int i = 0; i < N; i++)
        dp[i] = -1;
    std::cout << solve(0) << '\n';
}