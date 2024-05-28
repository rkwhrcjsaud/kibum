#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <map>

std::string s;
int M;
std::map<std::string, int> dp[101];

int solve(int idx, std::string prev)
{
    if (dp[idx].find(prev) != dp[idx].end())
        return dp[idx][prev];
    int &ret = dp[idx][prev];
    if (idx == M)
    {
        if (prev > s)
            return ret = 1;
        return ret = 0;
    }
    ret = idx % 2;
    for (int i = 0; i < 4; i++)
    {
        std::string next = prev;
        next[i] = (next[i] - '0' + 1) % 10 + '0';
        if (idx % 2)
        {
            if (solve(idx + 1, next) == 0)
                return ret = 0;
        }
        else
        {
            if (solve(idx + 1, next) == 1)
                return ret = 1;
        }
    }
    return ret;
}

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> s >> M;
    std::cout << (solve(0, s) ? "koosaga" : "cubelover") << '\n';
}