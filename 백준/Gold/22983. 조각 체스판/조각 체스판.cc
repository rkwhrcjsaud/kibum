#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <sstream>

int N, M;
int map[3002][3002];
int dp[3002][3002][2];

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N >> M;
    for (int i = 1; i <= N; i++)
    {
        std::string s;
        std::cin >> s;
        for (int j = 1; j <= M; j++)
            map[i][j] = s[j - 1] == 'B' ? 1 : 2;
    }
    long long ans = 0;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            if (map[i][j] == 1)
            {
                dp[i][j][0] = std::min(dp[i - 1][j][1], dp[i][j - 1][1]);
                dp[i][j][0] = std::min(dp[i - 1][j - 1][0], dp[i][j][0]) + 1;
            }
            else
            {
                dp[i][j][1] = std::min(dp[i - 1][j][0], dp[i][j - 1][0]);
                dp[i][j][1] = std::min(dp[i - 1][j - 1][1], dp[i][j][1]) + 1;
            }
            ans += std::max(dp[i][j][0], dp[i][j][1]);
        }
    }
    std::cout << ans << '\n';
}