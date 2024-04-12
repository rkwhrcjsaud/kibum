#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

int N, M;
std::vector<std::pair<int, int> > graph[101];
int dp[101][101];
bool isBase[101];

int solve(int idx, int base)
{
    if (idx == base)
        return 1;
    if (dp[idx][base])
        return dp[idx][base];
    int ret = 0;
    for (int i = 0; i < graph[idx].size(); i++)
    {
        int next = graph[idx][i].first;
        int cost = graph[idx][i].second;
        ret += solve(next, base) * cost;
    }
    return dp[idx][base] = ret;
}

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N >> M;
    std::fill(isBase, isBase + 101, true);
    for (int i = 1; i <= M; i++)
    {
        int a, b, c;
        std::cin >> a >> b >> c;
        graph[a].push_back(std::make_pair(b, c));
        isBase[a] = false;
    }
    for (int i = 1; i <= N; i++)
    {
        if (isBase[i])
            std::cout << i << ' ' << solve(N, i) << '\n';
    }
}