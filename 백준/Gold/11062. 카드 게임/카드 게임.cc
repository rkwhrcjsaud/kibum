#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

int T;
int dp[1001][1001];
std::vector<int> v;

int solve(int left, int right, bool turn)
{
    if (left > right)
        return 0;
    int &ret = dp[left][right];
    if (ret != -1)
        return ret;
    if (turn)
        return ret = std::max(v[left] + solve(left + 1, right, false),
                              v[right] + solve(left, right - 1, false));
    else
        return ret = std::min(solve(left + 1, right, true),
                              solve(left, right - 1, true));
}

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> T;
    while (T--)
    {
        int N;
        std::cin >> N;
        for (int i = 1; i <= N; i++)
        {
            int a;
            std::cin >> a;
            v.push_back(a);
        }
        std::fill(&dp[0][0], &dp[1000][1001], -1);
        std::cout << solve(0, N - 1, true) << '\n';
        v.clear();
    }
}