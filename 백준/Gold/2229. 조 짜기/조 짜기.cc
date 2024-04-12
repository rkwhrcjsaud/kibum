#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

int N;
int arr[1001];
int dp[1001];

int solve(int idx)
{
    if (idx == N)
        return 0;
    if (dp[idx] != -1)
        return dp[idx];
    int ret = 0;
    for (int i = idx; i <= N; i++)
    {
        int max_val = 0, min_val = 10001;
        for (int j = idx; j <= i; j++)
        {
            max_val = std::max(max_val, arr[j]);
            min_val = std::min(min_val, arr[j]);
        }
        ret = std::max(ret, solve(i + 1) + max_val - min_val);
    }
    return dp[idx] = ret;
}

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N;
    for (int i = 1; i <= N; i++)
        std::cin >> arr[i];
    std::fill(&dp[0], &dp[1001], -1);
    std::cout << solve(1) << '\n';
}