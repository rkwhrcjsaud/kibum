#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <sstream>
#include <map>
#include <queue>

int N;
int arr[5001];
int dp[5001][11][11][11];

int calc(int a, int b)
{
    return std::min(std::abs(a - b), 10 - std::abs(a - b));
}

int solve(int idx, int a, int b, int c)
{
    if (idx == N)
        return 0;
    int &ret = dp[idx][a][b][c];
    if (ret != -1)
        return ret;
    ret = 1e9;
    ret = std::min(ret, solve(idx + 1, arr[idx], b, c) + calc(a, arr[idx]));
    ret = std::min(ret, solve(idx + 1, a, arr[idx], c) + calc(b, arr[idx]));
    ret = std::min(ret, solve(idx + 1, a, b, arr[idx]) + calc(c, arr[idx]));
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
    std::cout << solve(0, 0, 0, 0) << '\n';
}