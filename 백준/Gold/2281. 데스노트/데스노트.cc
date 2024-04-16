#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

int N, M;
std::vector<int> v;
int dp[1001];

int solve(int idx)
{
    if (idx == N)
        return 0;
    if (dp[idx] != 1e9)
        return dp[idx];
    int &ret = dp[idx];
    int cnt = v[idx];
    for (; idx < N && cnt <= M;)
    {
        ret = std::min(ret, solve(idx + 1) + (M - cnt) * (M - cnt));
        cnt += v[++idx] + 1;
    }
    if (idx == N)
        return ret = 0;
    return ret;
}

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        int num;
        std::cin >> num;
        v.push_back(num);
    }
    std::fill(&dp[0], &dp[1000], 1e9);
    std::cout << solve(0) << '\n';
}