#include <iostream>
#include <vector>
#include <algorithm>

int N, M, P;
long long dp[101][101];
const int MOD = 1000000007;

long long solve(int idx, int x)
{
    if (idx == P)
    {
        if (x == N)
            return 1;
        return 0;
    }
    long long &ret = dp[idx][x];
    if (ret != -1)
        return ret;
    ret = 0;
    if (x < N)
        ret += solve(idx + 1, x + 1) * (N - x);
    if (x > M)
        ret += solve(idx + 1, x) * (x - M);
    ret %= MOD;
    return ret;
}

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N >> M >> P;
    std::fill(&dp[0][0], &dp[100][101], -1);
    std::cout << solve(0, 0) << std::endl;
}