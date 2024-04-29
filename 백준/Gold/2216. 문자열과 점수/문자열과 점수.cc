#include <iostream>
#include <vector>
#include <algorithm>

int A, B, C;
std::string s1, s2;
int len1, len2;
int dp[3001][3001];

int solve(int i, int j)
{
    if (i == len1 || j == len2)
        return std::max(len1 - i, len2 - j) * B;
    int &ret = dp[i][j];
    if (ret != -1)
        return ret;
    ret = 0;
    if (s1[i] == s2[j])
        ret = solve(i + 1, j + 1) + A;
    else
    {
        ret = std::max(solve(i + 1, j), solve(i, j + 1)) + B;
        ret = std::max(ret, solve(i + 1, j + 1) + std::max(C, B * 2));
    }
    return ret;
}

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> A >> B >> C;
    std::cin >> s1 >> s2;
    len1 = s1.length();
    len2 = s2.length();
    std::fill(&dp[0][0], &dp[3000][3001], -1);
    std::cout << solve(0, 0) << '\n';
}