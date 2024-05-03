#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

int N;
int arr[2001];
int dp[2001][2001];

int solve(int l, int r)
{
    if (l == r)
        return arr[l] * N;
    int &ret = dp[l][r];
    if (ret != -1)
        return ret;
    int turn = N - (r - l);
    ret = std::max(solve(l + 1, r) + arr[l] * turn, solve(l, r - 1) + arr[r] * turn);
    return ret;
}

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N;
    for (int i = 0; i < N; i++)
        std::cin >> arr[i];
    memset(dp, -1, sizeof(dp));
    std::cout << solve(0, N - 1) << '\n';
}
