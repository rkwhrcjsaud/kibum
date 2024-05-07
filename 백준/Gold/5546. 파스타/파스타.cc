#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

int N, K;
int dp[101][4][4];
int arr[101];
const int MOD = 10000;

int solve(int idx, int cur, int prev)
{
    if (idx == N)
        return 1;
    int &ret = dp[idx][cur][prev];
    if (ret != -1)
        return ret;
    ret = 0;
    if (arr[idx] != 0)
    {
        if (arr[idx] == cur && cur == prev)
            return ret;
        ret += solve(idx + 1, arr[idx], cur);
        ret %= MOD;
    }
    else
    {
        for (int i = 1; i <= 3; i++)
        {
            if (i == cur && cur == prev)
                continue ;
            ret += solve(idx + 1, i, cur);
            ret %= MOD;
        }
    }
    return ret;
}

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N >> K;
    memset(dp, -1, sizeof(dp));
    for (int i = 0; i < K; i++)
    {
        int a, b;
        std::cin >> a >> b;
        arr[a - 1] = b;
    }
    std::cout << solve(0, 0, 0) << '\n';
}