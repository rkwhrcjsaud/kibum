#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

std::string s;
int len;
int dp[1000001][3];
const int MOD = 1e9 + 7;

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> s;
    len = s.size();
    dp[0][0] = s[0] == 'a';
    for (int i = 1; i < len; i++)
    {
        dp[i][0] = dp[i - 1][0];
        dp[i][1] = dp[i - 1][1];
        dp[i][2] = dp[i - 1][2];
        if (s[i] == 'a')
        {
            dp[i][0] = dp[i - 1][0] * 2;
            dp[i][0] %= MOD;
            dp[i][0] += 1;
            dp[i][0] %= MOD;
        }
        else if (s[i] == 'b')
        {
            dp[i][1] = dp[i - 1][1] * 2;
            dp[i][1] %= MOD;
            dp[i][1] += dp[i - 1][0];
            dp[i][1] %= MOD;
        }
        else if (s[i] == 'c')
        {
            dp[i][2] = dp[i - 1][2] * 2;
            dp[i][2] %= MOD;
            dp[i][2] += dp[i - 1][1];
            dp[i][2] %= MOD;
        }
    }
    std::cout << dp[len - 1][2] << '\n';
}