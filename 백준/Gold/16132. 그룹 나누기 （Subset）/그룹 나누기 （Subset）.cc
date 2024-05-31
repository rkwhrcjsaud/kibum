#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

int N;
int half;
long long dp[50][600][600];

long long solve(int idx, int sum1, int sum2)
{
    if (idx == N)
    {
        if ((sum1 == N && sum2 == 0)
            || sum1 == 0 && sum2 == N)
            return 1;
        return 0;
    }
    long long &ret = dp[idx][sum1][sum2];
    if (ret != -1)
        return ret;
    ret = 0;
    if (sum1 >= idx)
        ret += solve(idx + 1, sum1 - idx, sum2);
    if (sum2 >= idx)
        ret += solve(idx + 1, sum1, sum2 - idx);
    return dp[idx][sum2][sum1] = ret;
}

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N;
    if ((N * (N + 1)) % 4 != 0)
    {
        std::cout << 0 << '\n';
        return 0;
    }
    half = N * (N + 1) / 4;
    memset(dp, -1, sizeof(dp));
    std::cout << solve(1, half, half) / 2 << '\n';
}