#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>

int N, M;
int map[51][51];
int sum[51][51];
int dp[51][51][51][51];

int solve(int x1, int y1, int x2, int y2)
{
    if (x1 == x2 && y1 == y2)
        return 0;
    int &ret = dp[x1][y1][x2][y2];
    if (ret != -1)
        return ret;
    ret = 1e9;
    for (int i = x1; i < x2; i++)
    {
        ret = std::min(ret, solve(x1, y1, i, y2) + solve(i + 1, y1, x2, y2));
    }
    for (int i = y1; i < y2; i++)
    {
        ret = std::min(ret, solve(x1, y1, x2, i) + solve(x1, i + 1, x2, y2));
    }
    ret += sum[x2][y2] - sum[x1 - 1][y2] - sum[x2][y1 - 1] + sum[x1 - 1][y1 - 1];
    return ret;
}

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N >> M;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            std::cin >> map[i][j];
            sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + map[i][j];
        }
    }
    memset(dp, -1, sizeof(dp));
    std::cout << solve(1, 1, N, M) << '\n';
}
