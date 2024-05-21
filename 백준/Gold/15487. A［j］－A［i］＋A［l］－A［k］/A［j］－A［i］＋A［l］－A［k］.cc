#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <sstream>
#include <map>

int N;
int arr[1000001];
int dp[1000001][5];

int solve(int idx, int k)
{
    if (idx == N && k == 4)
        return 0;
    int &ret = dp[idx][k];
    if (ret != -1)
        return ret;
    ret = -1e9;
    if (N - idx - 1 >= 4 - k)
        ret = std::max(ret, solve(idx + 1, k));
    if (k < 4)
        ret = std::max(ret, solve(idx + 1, k + 1) + arr[idx] * (k % 2 == 0 ? -1 : 1));
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
    std::cout << solve(0, 0) << '\n';
}