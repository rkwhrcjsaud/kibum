#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <sstream>

int N, total;
int bright[200001];
int dp[200001];

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N;
    for (int i = 1; i <= N; i++)
        std::cin >> bright[i];
    for (int i = 1; i <= N; i++)
    {
        int flag;
        std::cin >> flag;
        if (flag)
        {
            total += bright[i];
            bright[i] = -bright[i];
        }
    }
    int ans = -1e9;
    for (int i = 1; i <= N; i++)
    {
        dp[i] = std::max(dp[i - 1] + bright[i], bright[i]);
        ans = std::max(ans, dp[i]);
    }
    std::cout << total + ans << '\n';
}