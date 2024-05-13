#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

int N, M, K;
bool map[1001][1001];
int dp[1001][1001];
const int MOD = 1e9 + 7;

int solve(int x, int y)
{
    if (x <= 0 || y <= 0 || x > N || y > M || map[x][y])
        return 0;
    if (x == N && y == M)
        return 1;
    if (dp[x][y] != -1)
        return dp[x][y];
    int ret = 0;
    ret += solve(x + (y % 2 ? -1 : 1), y + 1);
    ret %= MOD;
    ret += solve(x, y + 1);
    ret %= MOD;
    ret += solve(x + 1, y);
    ret %= MOD;
    return dp[x][y] = ret % MOD;
}

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N >> M >> K;
    for (int i = 0; i < K; i++)
    {
        int a, b;
        std::cin >> a >> b;
        map[a][b] = true;
    }
    memset(dp, -1, sizeof(dp));
    std::cout << solve(1, 1) << '\n';
}
