#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <sstream>

int N;
std::string map[501];
int dp[501][501][4];
int d[2][2] = {{1, 0}, {0, 1}};
int name[4] = {'M', 'O', 'L', 'A'};

int solve(int x, int y, int k)
{
    if (x == N && y == N)
        return 0;
    int &ret = dp[x][y][k];
    if (ret != -1)
        return ret;
    ret = 0;
    for (int i = 0; i < 2; i++)
    {
        int nx = x + d[i][0];
        int ny = y + d[i][1];
        if (nx > N || ny > N)
            continue;
        if (map[nx][ny] == name[k])
            ret = std::max(ret, solve(nx, ny, (k + 1) % 4) + (k == 3 ? 1 : 0));
        else
            ret = std::max(ret, solve(nx, ny, map[nx][ny] == 'M' ? 1 : 0));
    }
    return ret;
}

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N;
    for (int i = 1; i <= N; i++)
    {
        std::cin >> map[i];
        map[i] = ' ' + map[i];
    }
    memset(dp, -1, sizeof(dp));
    std::cout << solve(1, 1, map[1][1] == 'M' ? 1 : 0) << '\n';
}