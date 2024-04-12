#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

int N;
int leftcard[2001];
int rightcard[2001];
int dp[2001][2001];

int solve(int left, int right)
{
    if (left == N || right == N)
        return 0;
    int &ret = dp[left][right];
    if (ret != -1)
        return ret;
    if (leftcard[left] > rightcard[right])
        return ret = std::max(solve(left, right + 1) + rightcard[right],
                              std::max(solve(left + 1, right + 1),
                                        solve(left + 1, right)));
    else
        return ret = std::max(solve(left + 1, right + 1),
                              solve(left + 1, right));
}

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N;
    for (int i = 0; i < N; i++)
        std::cin >> leftcard[i];
    for (int i = 0; i < N; i++)
        std::cin >> rightcard[i];
    std::fill(&dp[0][0], &dp[2000][2001], -1);
    std::cout << solve(0, 0) << '\n';
}