#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#include <cmath>

int N, B;
int arr[3001];
int dp[3001][3001][2];

int solve(int idx, int b, int flag)
{
    if (idx == N)
        return 0;
    if (b == 0)
        return 0;
    int &ret = dp[idx][b][flag];
    if (ret != -1)
        return ret;
    ret = 0;
    ret = std::max(ret, solve(idx + 1, b, 0));
    ret = std::max(ret, solve(idx + 1, b - 1, 1) + arr[idx] * flag);
    return ret;
}

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N >> B;
    for (int i = 0; i < N; i++)
        std::cin >> arr[i];
    memset(dp, -1, sizeof(dp));
    std::cout << solve(0, B, 0) << '\n';
}