#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

typedef long long ll;
ll D, M;
ll dp[4001][4001];

ll solve(int d, int h)
{
    if (d == D)
        return h == 0 ? 1 : 0;
    if (h == 0 && d != 0)
        return 0;
    ll &ret = dp[d][h];
    if (ret != -1)
        return ret;
    ret = 0;
    for (int i = -1; i <= 1; i++)
    {
        if (i == 0)
            continue;
        if (h + i >= 0)
        {
            ret += solve(d + 1, h + i);
            ret %= M;
        }
    }
    return ret;
}

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> D >> M;
    memset(dp, -1, sizeof(dp));
    std::cout << solve(0, 0) << '\n';
}
