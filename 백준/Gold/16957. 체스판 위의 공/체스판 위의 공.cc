#include <iostream>
#include <queue>
#include <vector>
#include <sstream>
#include <cstring>
#include <climits>

typedef std::pair<int, int> pii;
int R, C;
int map[501][501];
int ans[501][501];
pii dp[501][501];
int dydx[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};

pii solve(int y, int x)
{
    if (dp[y][x] != std::make_pair(y, x))
        return dp[y][x];
    int min = map[y][x];
    pii coord = std::make_pair(y, x);
    for (int i = 0; i < 8; i++)
    {
        int ny = y + dydx[i][0];
        int nx = x + dydx[i][1];
        if (ny < 1 || nx < 1 || ny > R || nx > C)
            continue;
        if (map[ny][nx] < min)
        {
            min = map[ny][nx];
            coord = std::make_pair(ny, nx);
        }
    }
    if (coord != std::make_pair(y, x))
        return dp[y][x] = solve(coord.first, coord.second);
    return dp[y][x] = coord;
}

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> R >> C;
    for (int i = 1; i <= R; i++)
    {
        for (int j = 1; j <= C; j++)
        {
            std::cin >> map[i][j];
            dp[i][j] = std::make_pair(i, j);
        }
    }
    for (int i = 1; i <= R; i++)
    {
        for (int j = 1; j <= C; j++)
        {
            pii coord = solve(i, j);
            ans[coord.first][coord.second]++;
        }
    }
    for (int i = 1; i <= R; i++)
    {
        for (int j = 1; j <= C; j++)
        {
            std::cout << ans[i][j] << ' ';
        }
        std::cout << '\n';
    }
}