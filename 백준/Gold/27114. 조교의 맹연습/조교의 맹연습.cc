#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <sstream>
#include <map>

int A, B, C, K;
int dp[1000001][4];

int solve(int k, int dir)
{
    if (k < 0)
        return 1e9;
    if (k == 0 && dir == 0)
        return 0;
    int &ret = dp[k][dir];
    if (ret != -1)
        return ret;
    ret = 1e9;
    ret = std::min(ret, solve(k - A, (dir + 1) % 4) + 1);
    ret = std::min(ret, solve(k - B, (dir + 3) % 4) + 1);
    ret = std::min(ret, solve(k - C, (dir + 2) % 4) + 1);
    return ret;
}

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> A >> B >> C >> K;
    memset(dp, -1, sizeof(dp));
    int ans = solve(K, 0);
    if (ans == 1e9)
        std::cout << -1 << '\n';
    else
        std::cout << ans << '\n';
}