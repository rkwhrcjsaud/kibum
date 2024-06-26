#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <sstream>
#include <map>
#include <queue>
#include <cmath>

int N, M, S, E;
double dp[502][10001];

double solve(int col, int row)
{
    if (row == M)
        return col == E ? 1 : 0;
    double &ret = dp[col][row];
    if (ret != -1)
        return ret;
    ret = 0;
    if (col > 1)
        ret += solve(col - 1, row + 1) / (double)(N - 1);
    if (col < N)
        ret += solve(col + 1, row + 1) / (double)(N - 1);
    if (col == 1 || col == N)
        ret += solve(col, row + 1) * ((double)(N - 2) / (N - 1));
    else
        ret += solve(col, row + 1) * ((double)(N - 3) / (N - 1));
    return ret;
}

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N >> M >> S >> E;
    for (int i = 1; i <= N; i++)
        for (int j = 0; j <= M; j++)
            dp[i][j] = -1;
    std::cout << std::fixed;
    std::cout.precision(10);
    std::cout << solve(S, 0) << '\n';
}