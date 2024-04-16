#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

int N, M, K;
std::vector< std::pair<int, int> > v[301];
int dp[301][301];

int solve(int city, int cnt)
{
    if (city == N)
        return 0;
    if (dp[city][cnt] != -1)
        return dp[city][cnt];
    int ret = 0;
    for (int i = 0; i < v[city].size(); i++)
    {
        int next = v[city][i].first;
        int cost = v[city][i].second;
        if (cnt + 1 <= M)
            ret = std::max(ret, solve(next, cnt + 1) + cost);
    }
    if (ret == 0)
        return dp[city][cnt] = -1e9;
    return dp[city][cnt] = ret;
}

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N >> M >> K;
    for (int i = 0; i < K; i++)
    {
        int a, b, c;
        std::cin >> a >> b >> c;
        if (a > b)
            continue ;
        v[a].push_back(std::make_pair(b, c));
    }
    std::fill(&dp[0][0], &dp[300][300], -1);
    std::cout << solve(1, 1) << '\n';
}