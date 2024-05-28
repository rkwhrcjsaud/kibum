#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <map>

int N, M;
int arr[101];
int dp[1 << 11][101][101];

int solve(int prev, int idx, int m)
{
    if (idx == N)
    {
        if (m % 2 == 0)
            return prev;
        return 0;
    }
    int &ret = dp[prev][idx][m];
    if (ret != -1)
        return ret;
    ret = 0;
    if (m > 0)
        ret = std::max(ret, solve(prev ^ arr[idx], idx + 1, m - 1));
    ret = std::max(ret, solve(prev, idx + 1, m));
    return ret;
}

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        int num;
        std::cin >> num;
        arr[i] = std::abs(num);
    }
    memset(dp, -1, sizeof(dp));
    std::cout << solve(0, 0, M) << '\n';
}