#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

int N, M;
int arr[100001][11];
int dp[100001][11];

int solve(int idx, int last)
{
    if (idx == N)
        return 0;
    int &ret = dp[idx][last];
    if (ret != -1)
        return ret;
    ret = 0;
    for (int i = 0; i < M; i++)
    {
        if (i == last)
        {
            ret = std::max(ret, solve(idx + 1, i) + arr[idx][i] / 2);
            continue ;
        }
        ret = std::max(ret, solve(idx + 1, i) + arr[idx][i]);
    }
    return ret;
}

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N >> M;
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
            std::cin >> arr[j][i];
    }
    memset(dp, -1, sizeof(dp));
    std::cout << solve(0, 10) << '\n';
}
