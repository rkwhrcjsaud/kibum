#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

int N, T;
int max;
std::vector<std::pair<int, int> > v;
int dp[101][10001];

int solve(int idx, int time)
{
    if (idx == N)
        return 0;
    if (dp[idx][time] != -1)
        return dp[idx][time];
    int ret = 0;
    if (time + v[idx].first <= T)
        ret = std::max(ret, solve(idx + 1, time + v[idx].first) + v[idx].second);
    ret = std::max(ret, solve(idx + 1, time));
    return dp[idx][time] = ret;
}

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N >> T;
    for (int i = 0; i < N; i++)
    {
        int a, b;
        std::cin >> a >> b;
        v.push_back(std::make_pair(a, b));
    }
    std::fill(&dp[0][0], &dp[100][10001], -1);
    std::cout << solve(0, 0) << '\n';
}