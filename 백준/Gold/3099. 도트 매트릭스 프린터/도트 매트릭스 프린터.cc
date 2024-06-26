#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <sstream>
#include <map>
#include <queue>
#include <cmath>

std::string str;
int dp[10001][28];

int solve(int idx, int prev)
{
    if (idx == str.size())
        return 0;
    int &ret = dp[idx][prev];
    int c = str[idx] - 'A';
    if (ret != -1)
        return ret;
    ret = 1e9;
    if (prev == c)
        ret = std::min(ret, solve(idx + 1, prev) + 1);
    else
    {
        ret = std::min(ret, solve(idx + 1, prev) + 2);
        ret = std::min(ret, solve(idx + 1, c) + 2);
    }
    return ret;
}

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> str;
    memset(dp, -1, sizeof(dp));
    std::cout << solve(0, 26) << '\n';
}