#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <sstream>
#include <map>
#include <queue>
#include <cmath>

int N;
typedef long long ll;
ll dp[401][401];
int max[401][401];

ll solve(int l, int r)
{
    if (l == r)
        return 0;
    ll &ret = dp[l][r], i = l;
    if (ret != -1)
        return ret;
    for (ret = 1e18; i < r; i++)
        ret = std::min(ret, solve(l, i) + solve(i + 1, r) + max[l][i] + max[i + 1][r]);
    return ret;
}

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N;
    for (int i = 0; i < N; i++)
        std::cin >> max[i][i];
    for (int i = 0; i < N; i++)
        for (int j = i + 1; j < N; j++)
            max[i][j] = std::max(max[i][j - 1], max[j][j]);
    memset(dp, -1, sizeof(dp));
    std::cout << solve(0, N - 1) << '\n';
}