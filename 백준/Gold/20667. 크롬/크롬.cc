#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

int N, M, K;
struct Tab {
    int cpu, mem, priority;
};
Tab tabs[101];
int dp[501][1001];

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N >> M >> K;
    for (int i = 1; i <= N; i++)
        std::cin >> tabs[i].cpu >> tabs[i].mem >> tabs[i].priority;
    memset(dp, -1, sizeof(dp));
    dp[0][0] = 0;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 500; j >= 0; j--)
        {
            for (int k = 1000; k >= 0; k--)
            {
                if (dp[j][k] == -1 || tabs[i].priority + j > 500)
                    continue;
                if (k + tabs[i].cpu > M)
                    dp[j + tabs[i].priority][M] = std::max(dp[j + tabs[i].priority][M], dp[j][k] + tabs[i].mem);
                else
                    dp[j + tabs[i].priority][k + tabs[i].cpu] = std::max(dp[j + tabs[i].priority][k + tabs[i].cpu], dp[j][k] + tabs[i].mem);
            }
        }
    }
    int ans = -1;
    for (int i = 0; i <= 500; i++)
    {
        if (dp[i][M] >= K)
        {
            ans = i;
            break;
        }
    }
    std::cout << ans << '\n';
}
