#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <map>

int N;
int arr[1001][1001];
int dp[1001][1001][2][4];
int d[4][2] = {{0, -1}, {-1, 0}, {-1, -1}, {-1, 1}};
int ans;

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N;
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            std::cin >> arr[i][j];
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            if (arr[i][j] == 1)
            {
                for (int k = 0; k < 4; k++)
                {
                    dp[i][j][0][k] = dp[i + d[k][0]][j + d[k][1]][0][k] + 1;
                    dp[i][j][1][k] = dp[i + d[k][0]][j + d[k][1]][1][k] + 1;
                    ans = std::max(ans, std::max(dp[i][j][0][k], dp[i][j][1][k]));
                }
            }
            else if (arr[i][j] == 2)
            {
                for (int k = 0; k < 4; k++)
                {
                    dp[i][j][1][k] = dp[i + d[k][0]][j + d[k][1]][0][k] + 1;
                    ans = std::max(ans, dp[i][j][1][k]);
                }
            }
        }
    }
    std::cout << ans << '\n';
}