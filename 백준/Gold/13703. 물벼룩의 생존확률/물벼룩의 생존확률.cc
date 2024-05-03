#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

int K, N;
long long dp[128][64];

long long solve(int t, int depth)
{
    if (t == N && depth != 0)
        return 1;
    if (depth == 0)
        return 0;
    long long &ret = dp[depth][t];
    if (ret != -1)
        return ret;
    ret = 0;
    ret += solve(t + 1, depth + 1);
    ret += solve(t + 1, depth - 1);
    return ret;
}

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> K >> N;
    memset(dp, -1, sizeof(dp));
    std::cout << solve(0, K) << '\n';
}
