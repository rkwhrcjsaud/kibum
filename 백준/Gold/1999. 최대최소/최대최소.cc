#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <sstream>

int N, B, K;
int map[251][251];
int dp[251][251][251][2];

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N >> B >> K;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            std::cin >> map[i][j];
            dp[i][j][1][0] = map[i][j];
            dp[i][j][1][1] = map[i][j];
        }
    }
    for (int k = 2; k <= B; k++)
    {
        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= N; j++)
            {
                dp[i][j][k][0] = std::min(map[i][j], 
                    std::min(dp[i - 1][j][k - 1][0], 
                    std::min(dp[i - 1][j - 1][k - 1][0], 
                    dp[i][j - 1][k - 1][0])));
                dp[i][j][k][1] = std::max(map[i][j], 
                    std::max(dp[i - 1][j][k - 1][1], 
                    std::max(dp[i - 1][j - 1][k - 1][1], 
                    dp[i][j - 1][k - 1][1])));
            }
        }
    }
    for (int i = 0; i < K; i++)
    {
        int a, b;
        std::cin >> a >> b;
        std::cout << dp[a + B - 1][b + B - 1][B][1] - dp[a + B - 1][b + B - 1][B][0] << '\n';
    }
}