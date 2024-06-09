#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#include <cmath>

int N;
int arr[501];
int max[501][501];
int dp[501][501];

int solve(int l, int r)
{
    if (l == r)
        return 0;
    int &ret = dp[l][r];
    if (ret != -1)
        return ret;
    ret = 1e9;
    for (int i = l; i < r; i++)
        ret = std::min(ret, solve(l, i) + solve(i + 1, r) + std::abs(max[l][i] - max[i + 1][r]));
    return ret;
}

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N;
    for (int i = 1; i <= N; i++)
        std::cin >> arr[i];
    for (int i = 1; i <= N; i++)
    {
        max[i][i] = arr[i];
        for (int j = i + 1; j <= N; j++)
            max[i][j] = std::max(max[i][j - 1], arr[j]);
    }
    std::memset(dp, -1, sizeof(dp));
    std::cout << solve(1, N) << '\n';
}