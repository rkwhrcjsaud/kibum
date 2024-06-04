#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#include <cmath>

std::string s1, s2;
int s1_len, s2_len;
int dp[1001][1001][2];

int solve(int i, int j, int flag)
{
    if (i == s1_len && j == s2_len)
        return 0;
    if (i == s1_len)
        return 1;
    if (j == s2_len)
        return 1e9;
    int &ret = dp[i][j][flag];
    if (ret != -1)
        return ret;
    ret = 1e9;
    if (s1[i] == s2[j])
        ret = std::min(ret, solve(i + 1, j + 1, 0));
    ret = std::min(ret, solve(i, j + 1, 1) + (flag ? 0 : 1));
    return ret;
}

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::getline(std::cin, s1);
    std::getline(std::cin, s2);
    s1_len = s1.length();
    s2_len = s2.length();
    memset(dp, -1, sizeof(dp));
    int ans = solve(0, 0, 0);
    if (ans >= 1e9)
        std::cout << "-1\n";
    else
        std::cout << ans << '\n';
}