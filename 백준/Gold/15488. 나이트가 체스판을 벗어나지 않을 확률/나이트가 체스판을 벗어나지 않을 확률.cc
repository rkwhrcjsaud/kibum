#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <sstream>
#include <map>

typedef double db;
int N, startx, starty, K;
db dp[51][51][51];
int d[8][2] = {{1, 2}, {1, -2}, {-1, 2}, {-1, -2}, {2, 1}, {2, -1}, {-2, 1}, {-2, -1}};

db solve(int x, int y, int k)
{
    if (dp[x][y][k] != -1)
        return dp[x][y][k];
    if (k == 0)
        return 1.0;
    dp[x][y][k] = 0;
    db &ret = dp[x][y][k];
    for (int i = 0; i < 8; i++)
    {
        int nx = x + d[i][0];
        int ny = y + d[i][1];
        if (nx <= 0 || nx > N || ny <= 0 || ny > N)
            continue;
        ret += solve(nx, ny, k - 1) * (1.0 / 8.0);
    }
    return ret;
}

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N >> startx >> starty >> K;
    for (int i = 0; i <= N; i++)
    {
        for (int j = 0; j <= N; j++)
        {
            for (int k = 0; k <= K; k++)
                dp[i][j][k] = -1;
        }
    }
    std::cout.precision(10);
    std::cout << solve(startx, starty, K) << '\n';
}