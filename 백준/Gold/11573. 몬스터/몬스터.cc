#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <sstream>
#include <map>
#include <queue>
#include <cmath>

int T;
int R, Y, B;
double dp[101][101][101][3];

double solve(int r, int y, int b, int flag)
{
    if (r < 0 || y < 0 || b < 0)
        return 0;
    if (flag == 0 && r != 0 && y == 0 && b == 0)
        return 1;
    if (flag == 0 && r == 0)
        return 0;
    if (flag == 1 && r == 0 && y != 0 && b == 0)
        return 1;
    if (flag == 1 && y == 0)
        return 0;
    if (flag == 2 && r == 0 && y == 0 && b != 0)
        return 1;
    if (flag == 2 && b == 0)
        return 0;
    if (dp[r][y][b][flag] != -1)
        return dp[r][y][b][flag];
    double &ret = dp[r][y][b][flag];
    ret = 0;
    double rb = ((r && b) ? 1 : 0) * (double)r / (r + y + b) * b / (r + y + b - 1);
    double yr = ((y && r) ? 1 : 0) * (double)y / (r + y + b) * r / (r + y + b - 1);
    double by = ((b && y) ? 1 : 0) * (double)b / (r + y + b) * y / (r + y + b - 1);
    if (r && b)
        ret += solve(r - 1, y, b, flag) * rb / (rb + yr + by);
    if (y && r)
        ret += solve(r, y - 1, b, flag) * yr / (rb + yr + by);
    if (b && y)
        ret += solve(r, y, b - 1, flag) * by / (rb + yr + by);
    return ret;
}

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> T;
    while (T--)
    {
        std::cin >> R >> Y >> B;
        for (int i = 0; i <= R; i++)
            for (int j = 0; j <= Y; j++)
                for (int k = 0; k <= B; k++)
                    for (int l = 0; l < 3; l++)
                        dp[i][j][k][l] = -1;
        std::cout << std::fixed;
        std::cout.precision(10);
        std::cout << solve(R, Y, B, 0) << ' ';
        std::cout << solve(R, Y, B, 1) << ' ';
        std::cout << solve(R, Y, B, 2) << '\n';
    }
}
