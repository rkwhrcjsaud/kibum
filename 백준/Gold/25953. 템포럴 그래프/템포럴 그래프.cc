#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <sstream>
#include <map>

int N, T, M;
int s, e;
std::vector<std::pair<int, int> > v[1001][10001];
int dp[1001][10001];

int solve(int t, int node)
{
    if (t == T && node == e)
        return 0;
    if (t == T)
        return 1e9;
    int &ret = dp[t][node];
    if (ret != -1)
        return ret;
    ret = 1e9;
    ret = std::min(ret, solve(t + 1, node));
    for (int i = 0; i < v[t][node].size(); i++)
    {
        int next = v[t][node][i].first;
        int cost = v[t][node][i].second;
        ret = std::min(ret, solve(t + 1, next) + cost);
    }
    return ret;
}

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N >> T >> M;
    std::cin >> s >> e;
    for (int i = 0; i < T; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            int a, b, c;
            std::cin >> a >> b >> c;
            v[i][a].push_back(std::make_pair(b, c));
            v[i][b].push_back(std::make_pair(a, c));
        }
    }
    memset(dp, -1, sizeof(dp));
    int ans = solve(0, s);
    if (ans == 1e9)
        std::cout << "-1\n";
    else
        std::cout << ans << '\n';
}