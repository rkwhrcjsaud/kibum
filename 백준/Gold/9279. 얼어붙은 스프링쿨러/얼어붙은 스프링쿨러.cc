#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <sstream>
#include <map>
#include <queue>
#include <cmath>

int N, C;
std::vector< std::pair<int, int> > v[1002];
int dp[1002];

int solve(int node, int prev)
{
    int &ret = dp[node];
    if (ret != -1)
        return ret;
    ret = 0;
    for (int i = 0; i < v[node].size(); i++)
    {
        int next = v[node][i].first;
        int cost = v[node][i].second;
        if (next == prev)
            continue;
        ret += std::min(cost, solve(next, node));
    }
    if (ret == 0)
        ret = 1e9;
    return ret; 
}

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    while (true)
    {
        std::cin >> N >> C;
        if (std::cin.eof())
            break;
        for (int i = 0; i < N - 1; i++)
        {
            int a, b, c;
            std::cin >> a >> b >> c;
            v[a].push_back(std::make_pair(b, c));
            v[b].push_back(std::make_pair(a, c));
        }
        memset(dp, -1, sizeof(dp));
        std::cout << solve(C, 0) << '\n';
        for (int i = 0; i <= 1000; i++)
            v[i].clear();
    }
}