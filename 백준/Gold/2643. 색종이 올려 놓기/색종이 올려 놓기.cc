#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

int N;
std::vector< std::pair<int, int> > v;
int dp[101][101];
int ans;

int solve(int idx, int prev)
{
    if (idx == N)
        return 0;
    if (dp[idx][prev] != -1)
        return dp[idx][prev];
    int ret = 0;
    if ((v[prev].second >= v[idx].second && v[prev].first >= v[idx].first)
        || v[prev].second >= v[idx].first && v[prev].first >= v[idx].second)
        ret = std::max(ret, solve(idx + 1, idx) + 1);
    ret = std::max(ret, solve(idx + 1, prev));
    return dp[idx][prev] = ret;
}

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N;
    for (int i = 0; i < N; i++)
    {
        int a, b;
        std::cin >> a >> b;
        if (a < b)
            std::swap(a, b);
        v.push_back(std::make_pair(a, b));
    }
    std::sort(v.begin(), v.end(), std::greater< std::pair<int, int> >());
    std::fill(&dp[0][0], &dp[100][101], -1);
    for (int i = 0; i < N; i++)
        ans = std::max(ans, solve(i, i));
    std::cout << ans << '\n';
}