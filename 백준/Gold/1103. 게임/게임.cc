#include <iostream>
#include <queue>
#include <vector>

int N, M, max;
int arr[51][51];
int dp[51][51];
int visited[51][51];
int dydx[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

int bfs(int y, int x)
{
    if (y < 0 || y >= N || x < 0 || x >= M || arr[y][x] == 0)
        return 0;
    if (visited[y][x] == 1)
    {
        std::cout << -1 << '\n';
        exit(0);
    }
    if (dp[y][x] != 0)
        return dp[y][x];
    visited[y][x] = 1;
    for (int i = 0; i < 4; i++)
    {
        int ny = y + dydx[i][0] * arr[y][x];
        int nx = x + dydx[i][1] * arr[y][x];
        dp[y][x] = std::max(dp[y][x], bfs(ny, nx) + 1);
    }
    visited[y][x] = 0;
    return dp[y][x];
}

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        std::string str;
        std::cin >> str;
        for (int j = 0; j < M; j++)
        {
            if (str[j] == 'H')
                arr[i][j] = 0;
            else
                arr[i][j] = str[j] - '0';
        }
    }
    std::cout << bfs(0, 0) << '\n';
}