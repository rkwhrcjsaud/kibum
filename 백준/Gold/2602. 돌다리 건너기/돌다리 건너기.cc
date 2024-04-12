#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

std::string str1, str2, str3;
int dp[21][101][2];

int solve(int idx, int cur, bool isStr1)
{
    if (idx == str3.size())
        return 1;
    int &ret = dp[idx][cur][isStr1];
    if (ret != -1)
        return ret;
    ret = 0;
    if (isStr1)
    {
        for (int i = cur; i < str1.size(); i++)
        {
            if (str1[i] == str3[idx])
                ret += solve(idx + 1, i + 1, false);
        }
    }
    else
    {
        for (int i = cur; i < str2.size(); i++)
        {
            if (str2[i] == str3[idx])
                ret += solve(idx + 1, i + 1, true);
        }
    }
    return ret;
}

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> str3 >> str1 >> str2;
    std::fill(&dp[0][0][0], &dp[20][100][2], -1);
    std::cout << solve(0, 0, true) + solve(0, 0, false) << '\n';
}