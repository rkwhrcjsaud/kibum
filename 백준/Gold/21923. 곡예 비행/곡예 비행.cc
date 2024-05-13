#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

int N, M;
int point[1001][1001];
int dp[1001][1001][2];

int solve(int x, int y, int dir)
{
    if (y > M || x > N || x < 1 || y < 1)
        return -1e9;
    if (y == M && x == N && dir == 1)
        return point[x][y];
    int &ret = dp[x][y][dir];
    if (ret != -1e9)
        return ret;
    ret = -1e9;
    if (dir == 0)
    {
        ret = std::max(ret, solve(x, y + 1, 0) + point[x][y]);
        ret = std::max(ret, solve(x - 1, y, 0) + point[x][y]);
        ret = std::max(ret, solve(x, y, 1) + point[x][y]);
    }
    else
    {
        ret = std::max(ret, solve(x + 1, y, 1) + point[x][y]);
        ret = std::max(ret, solve(x, y + 1, 1) + point[x][y]);
    }
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
            std::cin >> point[i][j];
            dp[i][j][0] = -1e9;
            dp[i][j][1] = -1e9;
        }
    }
    std::cout << solve(N, 1, 0) << '\n';
}
