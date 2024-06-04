#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#include <cmath>

int R, C, N;
int p[1010][3];
int dp[1010];

int solve(int idx)
{
    if (idx == N + 1)
        return 0;
    int &ret = dp[idx];
    if (ret != -1)
        return ret;
    ret = 1e9;
    for (int i = 1; i <= N + 1; i++)
    {
        if (p[idx][0] > p[i][0] || p[idx][1] > p[i][1] || i == idx)
            continue;
        int dist = std::abs(p[idx][0] - p[i][0]) + std::abs(p[idx][1] - p[i][1]);
        ret = std::min(ret, solve(i) - p[idx][2] + dist);
        ret = std::max(ret, 0);
    }
    return ret;
}

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> R >> C >> N;
    p[0][0] = 1;
    p[0][1] = 1;
    p[N + 1][0] = R;
    p[N + 1][1] = C;
    for (int i = 1; i <= N; i++)
        std::cin >> p[i][0] >> p[i][1] >> p[i][2];
    memset(dp, -1, sizeof(dp));
    std::cout << solve(0) << '\n';
}