#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <sstream>
#include <map>
#include <queue>

int N, M;
int map[1010][1010];
int dp[1010][1010][3];

int solve(int n, int m, int flag)
{
    if (n < 1 || n > N)
        return 0;
    if (m >= M)
        return map[n][m];
    int &ret = dp[n][m][flag];
    if (ret != -1)
        return ret;
    ret = 0;
    if (flag == 0)
    {
        ret = std::max(ret, solve(n, m + 2, 0) + map[n][m] + map[n][m + 1]);
        ret = std::max(ret, solve(n + 1, m + 1, 0) + map[n][m]);
        ret = std::max(ret, solve(n - 1, m + 1, 0) + map[n][m]);
    }
    else
    {
        if (flag == 1)
            ret = std::max(ret, solve(n + 1, m + 1, 1) + map[n][m]);
        else if (flag == 2)
            ret = std::max(ret, solve(n - 1, m + 1, 2) + map[n][m]);
        ret = std::max(ret, solve(n, m + 1, flag == 1 ? 2 : 1) + map[n][m]);
    }
    return ret;
}

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N >> M;
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++)
            std::cin >> map[i][j];
    memset(dp, -1, sizeof(dp));
    int ans = 0;
    for (int i = 0; i <= N + 1; i++)
        ans = std::max(ans, std::max(solve(i, 0, 0), std::max(solve(i, 0, 1), solve(i, 0, 2))));
    std::cout << ans << '\n';
}