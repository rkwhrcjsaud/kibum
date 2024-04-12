#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

int N, L;
int left, right;
int arr[21];
int dp[21][21][21];

int solve(int l, int r, int idx)
{
    if (l > r)
        std::swap(l, r);
    int &ret = dp[l][r][idx];
    if (idx == L)
        return 0;
    if (ret != -1)
        return ret;
    ret = std::min(solve(arr[idx], r, idx + 1) + std::abs(l - arr[idx]),
                   solve(l, arr[idx], idx + 1) + std::abs(r - arr[idx]));
    return ret;
}

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N >> left >> right >> L;
    for (int i = 0; i < L; i++)
        std::cin >> arr[i];
    std::fill(&dp[0][0][0], &dp[20][20][21], -1);
    std::cout << solve(left, right, 0) << '\n';
}