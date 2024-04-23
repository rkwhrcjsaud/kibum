#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

std::string s1, s2, ans = "";
std::string result = "";
int dp[41][41][41];
int max = 0;

int solve(int i, int j, int k)
{
    if (i == s1.size() || j == s2.size())
    {
        if (result.size() < ans.size())
            result = ans;
        return 0;
    }
    int &ret = dp[i][j][k];
    if (ret != -1)
        return ret;
    ret = 0;
    if (s1[i] == s2[j])
    {
        ans += s1[i];
        ret = solve(i + 1, j + 1, k + 1) + 1;
        ans.pop_back();
    }
    else
        ret = std::max(solve(i + 1, j, k), solve(i, j + 1, k));
    return ret;
}

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> s1 >> s2;
    memset(dp, -1, sizeof(dp));
    solve(0, 0, 0);
    std::cout << result << '\n';
}