#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <sstream>
#include <map>

int N;
std::vector<std::pair<int, int> > v[101];
int dp[101][101];

int solve(int g, int idx)
{
    if (g == 0 || idx == v[g].size())
        return 0;
    int &ret = dp[g][idx];
    if (ret != -1)
        return ret;
    ret = 0;
    for (int i = 0; i < v[g - 1].size(); i++)
    {
        ret = std::max(ret, solve(g - 1, i) 
            + (v[g - 1][i].second - v[g][idx].second)
            * (v[g - 1][i].second - v[g][idx].second));
    }
    ret += v[g][idx].first;
    return ret;
}

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N;
    int max = 0;
    for (int i = 0; i < N; i++)
    {
        int g, t;
        std::cin >> g >> t;
        v[g].push_back(std::make_pair(t, i));
        max = std::max(max, g);
    }
    memset(dp, -1, sizeof(dp));
    int ans = 0;
    for (int i = 0; i < v[max].size(); i++)
        ans = std::max(ans, solve(max, i));
    std::cout << ans << '\n';
}