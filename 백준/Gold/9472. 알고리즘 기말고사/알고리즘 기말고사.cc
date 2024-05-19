#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <sstream>
#include <map>

typedef long long ll;
int T, num, N, K;
ll dp[18][18];

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> T;
    while (T--)
    {
        std::cin >> num >> N >> K;
        std::cout << num << ' ';
        memset(dp, 0, sizeof(dp));
        dp[1][0] = 1;
        dp[2][0] = 2;
        dp[2][1] = 1;
        dp[2][2] = 1;
        for (int i = 3; i <= N; i++)
        {
            dp[i][0] = dp[i - 1][0] * i;
            for (int j = 1; j < i; j++)
                dp[i][j] = dp[i - 1][j] * (i - j) + dp[i - 1][j - 1] * j;
            dp[i][i] = (i - 1) * (dp[i - 1][i - 1] + dp[i - 2][i - 2]);
        }
        std::cout << dp[N][K] << '\n';
    }
}
