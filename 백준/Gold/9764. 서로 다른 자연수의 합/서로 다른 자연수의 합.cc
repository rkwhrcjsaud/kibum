#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

int T, N;
const int MOD = 100999;
int dp[2001][2001];

int solve(int num, int min)
{
    if (num == 0)
        return 1;
    int &ret = dp[num][min];
    if (ret)
        return ret;
    for (int i = min + 1; i <= num; i++)
    {
        ret += solve(num - i, i);
        ret %= MOD;
    }
    return ret;
}

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> T;
    while (T--)
    {
        std::cin >> N;
        std::cout << solve(N, 0) << '\n';
    }
}
