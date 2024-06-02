#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#include <cmath>

int N, M;
std::string s1, s2;
int dp[2010][2010][2];
int ans = 0;

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N >> M >> s1 >> s2;
    for (int i = N; i >= 0; i--)
    {
        for (int j = M; j >= 0; j--)
        {
            dp[i][j][0] = std::max(
                ((s1[i] == 'O') ? std::max(dp[i + 1][j][1] + 1, 0) : 0),
                ((s2[j] == 'O') ? std::max(dp[i][j + 1][1] + 1, 0) : 0));
            dp[i][j][1] = std::max(
                ((s1[i] == 'I') ? (dp[i + 1][j][0] + 1) : -5000),
                ((s2[j] == 'I') ? (dp[i][j + 1][0] + 1) : -5000));
            ans = std::max(ans, dp[i][j][1]);
        }
    }
    std::cout << ans << '\n';
}