#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

int N, M, K;
int skill[101][2];
int dp[101][101][101];

int solve(int idx, int m, int k)
{
    if (m == 0)
        return 0;
    if (idx == N)
        return 1e9;
    int &ret = dp[idx][m][k];
    if (ret != -1)
        return ret;
    ret = 1e9;
    ret = std::min(ret, solve(idx + 1, m, 0));
    if (m - skill[idx][0] >= 0)
    {
        ret = std::min(ret, solve(idx + 1, m - skill[idx][0], 0) + skill[idx][1] + K * k);
        ret = std::min(ret, solve(idx, m - skill[idx][0], k + 1) + skill[idx][1] + K * k);
    }
    return ret;
}

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N >> M >> K;
    for (int i = 0; i < N; i++)
        std::cin >> skill[i][1] >> skill[i][0];
    memset(dp, -1, sizeof(dp));
    std::cout << solve(0, M, 0) << '\n';
}
