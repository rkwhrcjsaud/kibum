#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>

int N;
int arr[200001];
int dp[200001][3][2];

int solve(int idx, int k, bool lr)
{
    if (idx > N || idx <= 0)
        return -1e9;
    if (idx == N)
        return 0;
    int &ret = dp[idx][k][lr];
    if (ret != -1)
        return ret;
    ret = -1e9;
    ret = std::max(ret, solve(idx + arr[idx] * (lr ? 1 : -1), k, lr) + 1);
    if (k > 0)
        ret = std::max(ret, solve(idx + arr[idx] * (lr ? -1 : 1), k - 1, !lr) + 1);
    return ret;
}

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N;
    for (int i = 1; i <= N; i++)
        std::cin >> arr[i];
    memset(dp, -1, sizeof(dp));
    int ans = solve(1, 2, true);
    if (ans < 0)
        std::cout << -1 << '\n';
    else
        std::cout << ans << '\n';
}
