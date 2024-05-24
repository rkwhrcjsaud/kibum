#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

const int MOD = 998244353;
int N, M;
typedef long long ll;
ll dp[1001][101][2];

ll solve(int idx, int prev, int flag)
{
    if (idx == N)
        return 1;
    ll &ret = dp[idx][prev][flag];
    if (ret != -1)
        return ret;
    ret = 0;
    if (flag == 0)
    {
        for (int i = 1; i <= M; i++)
            ret = (ret + solve(idx + 1, i, i > prev ? 1 : 0)) % MOD;
    }
    else
    {
        for (int i = prev; i <= M; i++)
            ret = (ret + solve(idx + 1, i, i > prev ? 1 : 0)) % MOD;
    }
    return ret;
}

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N >> M;
    memset(dp, -1, sizeof(dp));
    std::cout << solve(0, 101, 0) << '\n';
}
