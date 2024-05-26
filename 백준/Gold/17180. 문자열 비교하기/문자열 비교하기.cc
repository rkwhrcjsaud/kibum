#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

int N, M;
std::string s1, s2;
int dp[301][301][601];

int solve(int i, int j, int len)
{
    if (i == N && j == M)
        return 0;
    int &ret = dp[i][j][len];
    if (ret != -1)
        return ret;
    ret = 1e9;
    if (i < N)
        ret = std::min(ret, solve(i + 1, j, len + 1) + std::abs(s1[i] - s2[j]));
    if (j < M)
        ret = std::min(ret, solve(i, j + 1, len + 1) + std::abs(s1[i] - s2[j]));
    if (i < N && j < M)
        ret = std::min(ret, solve(i + 1, j + 1, len + 1) + std::abs(s1[i] - s2[j]));
    return ret;
}

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N >> M >> s1 >> s2;
    memset(dp, -1, sizeof(dp));
    std::cout << solve(0, 0, 0) << '\n';
}
