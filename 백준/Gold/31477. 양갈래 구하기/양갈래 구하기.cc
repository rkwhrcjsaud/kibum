#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <sstream>
#include <map>
#include <queue>

int N;
std::vector<std::pair<int, int> > v[100001];
int dp[100001];

int solve(int idx, int prev)
{
    int &ret = dp[idx];
    if (ret != -1)
        return ret;
    ret = 0;
    for (int i = 0; i < v[idx].size(); i++)
    {
        if (v[idx][i].first == prev)
            continue;
        int next = v[idx][i].first;
        int cost = v[idx][i].second;
        ret += std::min(cost, solve(next, idx));
    }
    if (ret == 0)
        ret = 1e9;
    return ret;
}

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N;
    for (int i = 0; i < N - 1; i++)
    {
        int a, b, c;
        std::cin >> a >> b >> c;
        v[a].push_back(std::make_pair(b, c));
        v[b].push_back(std::make_pair(a, c));
    }
    memset(dp, -1, sizeof(dp));
    std::cout << solve(1, 0) << '\n';
}