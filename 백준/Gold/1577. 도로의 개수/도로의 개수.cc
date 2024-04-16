#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

int N, M, K;
long long dp[101][101];
int road[101][101][2];
int dydx[2][2] = {{0, 1}, {1, 0}};

long long solve(int y, int x)
{
    if (y == M && x == N)
        return 1;
    if (dp[y][x] != -1)
        return dp[y][x];
    long long &ret = dp[y][x];
    ret = 0;
    for (int i = 0; i < 2; i++)
    {
        int ny = y + dydx[i][0];
        int nx = x + dydx[i][1];
        if (ny > M || nx > N)
            continue ;
        if (road[y][x][i] == 1)
            continue ;
        ret += solve(ny, nx);
    }
    return dp[y][x] = ret;
}

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N >> M >> K;
    for (int i = 0; i < K; ++i)
    {
        int a, b, c, d;
        std::cin >> a >> b >> c >> d;
        if (a > c) std::swap(a, c);
        else if (b > d) std::swap(b, d);
        if (a < c) road[b][a][0] = 1;
        else road[b][a][1] = 1;
    }
    std::fill(&dp[0][0], &dp[100][100], -1);
    std::cout << solve(0, 0) << '\n';
}