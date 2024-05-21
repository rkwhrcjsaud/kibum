#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <sstream>
#include <map>

int N, K;
std::vector< int > v[11];
int dp[11][2001];

int solve(int g, int k)
{
    if (k == 0 || g > 10)
        return 0;
    int &ret = dp[g][k];
    if (ret != -1)
        return ret;
    ret = 0;
    ret += std::max(ret, solve(g + 1, k));
    for (int i = 1; i <= k; i++)
    {
        if (i > v[g].size())
            break;
        ret = std::max(ret, v[g][i - 1] + solve(g + 1, k - i) + i * (i - 1));
    }
    return ret;
}

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N >> K;
    for (int i = 0; i < N; i++)
    {
        int c, g;
        std::cin >> c >> g;
        v[g].push_back(c);
    }
    for (int i = 1; i <= 10; i++)
    {
        if (v[i].empty())
            continue;
        std::sort(v[i].begin(), v[i].end(), std::greater<int>());
        for (int j = 1; j < v[i].size(); j++)
            v[i][j] += v[i][j - 1];
    }
    memset(dp, -1, sizeof(dp));
    std::cout << solve(1, K) << '\n';
}