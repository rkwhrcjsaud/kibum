#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <map>

std::string s1, s2;
int s1_len, s2_len;
int dp[1001][1001];

int solve(int s1_idx, int s2_idx)
{
    if (s1_idx == s1_len && s2_idx == s2_len)
        return 0;
    if (s1_idx == s1_len)
        return s2_len - s2_idx;
    if (s2_idx == s2_len)
        return s1_len - s1_idx;
    int &ret = dp[s1_idx][s2_idx];
    if (ret != -1)
        return ret;
    ret = 1e9;
    if (s1[s1_idx] == s2[s2_idx])
        ret = std::min(ret, solve(s1_idx + 1, s2_idx + 1) + 1);
    ret = std::min(ret, std::min(solve(s1_idx + 1, s2_idx) + 1, solve(s1_idx, s2_idx + 1) + 1));
    return ret;
}

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> s1 >> s2;
    s1_len = s1.size();
    s2_len = s2.size();
    memset(dp, -1, sizeof(dp));
    std::cout << solve(0, 0) << '\n';
}