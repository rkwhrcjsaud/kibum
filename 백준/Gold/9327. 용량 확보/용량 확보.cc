#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

int N, E, T;
int arr[101];
int dp[101][200001];

int solve(int idx, int e)
{
    if (idx == N && e * 2 >= E)
        return 0;
    if (idx == N)
        return 1e9;
    int &ret = dp[idx][e];
    if (ret != -1)
        return ret;
    ret = 1e9;
    ret = std::min(ret, solve(idx + 1, e + arr[idx]) + arr[idx]);
    ret = std::min(ret, solve(idx + 1, e));
    return ret;
}

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> T;
    while (T--)
    {
        std::cin >> N >> E;
        int total = 0;
        for (int i = 0; i < N; i++)
        {
            std::cin >> arr[i];
            total += arr[i];
        }
        if (total * 2 < E)
        {
            std::cout << "FULL" << '\n';
            continue ;
        }
        memset(dp, -1, sizeof(dp));
        std::cout << solve(0, 0) << '\n';
    }
}