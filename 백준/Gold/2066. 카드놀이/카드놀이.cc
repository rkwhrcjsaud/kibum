#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <sstream>
#include <map>

typedef double db;
std::string card[10][4];
std::map<std::string, db> dp;

db solve(std::string str)
{
    if (dp.find(str) != dp.end())
        return dp[str];
    if (str == "000000000")
        return 1.0;
    dp[str] = 0;
    db &ret = dp[str];
    std::vector<std::pair<int, int> > select;
    for (int i = 0; i < 9; i++)
    {
        if (str[i] == '0')
            continue;
        for (int j = 0; j < 9; j++)
        {
            if (i == j)
                continue;
            if (str[j] == '0')
                continue;
            if (card[i][str[i] - '1'][0] != card[j][str[j] - '1'][0])
                continue;
            select.push_back(std::make_pair(i, j));
        }
    }
    for (int i = 0; i < select.size(); i++)
    {
        std::string next = str;
        next[select[i].first]--;
        next[select[i].second]--;
        ret += solve(next) * (1.0 / (db)select.size());
    }
    return ret;
}

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 4; j++)
            std::cin >> card[i][j];
    }
    std::string str = "444444444";
    std::cout << solve(str) << '\n';
}