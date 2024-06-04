#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#include <cmath>

std::string s;
int s_len;
int dp[200001];

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> s;
    s_len = s.length();
    if (s_len == 1)
    {
        std::cout << (s[0] == '+' ? 10 : 1) << '\n';
        return 0;
    }
    else if (s_len == 2)
    {
        std::cout << 11 << '\n';
        return 0;
    }
    dp[0] = (s[0] == '+' ? 10 : 1);
    if (s[1] == '+')
        dp[1] = 1e9;
    else
        dp[1] = (s[0] == '+' ? 11 : 1e9);
    if (s[1] == '+')
        dp[2] = dp[0] + (s[2] == '+' ? 10 : 1);
    else
        dp[2] = dp[0] - (s[2] == '+' ? 10 : 1);
    for (int i = 3; i < s_len; i++)
    {
        int flag = 0;
        dp[i] = -1e9;
        if (dp[i - 2] != 1e9)
        {
            flag = 1;
            int tmp = (s[i] == '+' ? 10 : 1);
            dp[i] = (s[i - 1] == '+' ? dp[i - 2] + tmp : dp[i - 2] - tmp);
        }
        if (dp[i - 3] != 1e9 && s[i] == '-' && s[i - 1] == '+')
        {
            flag = 1;
            dp[i] = std::max(dp[i], (s[i - 2] == '+' ? dp[i - 3] + 11 : dp[i - 3] - 11));
        }
        if (!flag)
            dp[i] = -1e9;
    }
    std::cout << dp[s_len - 1] << '\n';
}