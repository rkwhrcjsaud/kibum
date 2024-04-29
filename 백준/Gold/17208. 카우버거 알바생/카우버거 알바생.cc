#include <iostream>
#include <vector>
#include <algorithm>

int N, M, K;
std::vector<std::pair<int, int> > v;
int dp[101][301][301];

int solve(int idx, int m, int k)
{
    if (idx == N)
        return 0;
    if (dp[idx][m][k] != 0)
        return dp[idx][m][k];
    int ret = 0;
    if (m >= v[idx].first && k >= v[idx].second)
        ret = std::max(solve(idx + 1, m - v[idx].first, k - v[idx].second) + 1, solve(idx + 1, m, k));
    else
        ret = solve(idx + 1, m, k);
    return dp[idx][m][k] = ret;
}

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N >> M >> K;
    for (int i = 0; i < N; i++)
    {
        int m, k;
        std::cin >> m >> k;
        v.push_back(std::make_pair(m, k));
    }
    std::cout << solve(0, M, K) << '\n';
}