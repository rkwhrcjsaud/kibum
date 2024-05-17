#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <sstream>

int T;
std::string str;
int len;
typedef long long ll;
ll dp[81][11][2];

ll solve(int idx, int prev, int flag)
{
    if (idx == len)
        return 1;
    ll &ret = dp[idx][prev][flag];
    if (ret != -1)
        return ret;
    ret = 0;
    for (int i = prev; i <= (flag ? (str[idx] - '0') : 9); i++)
        ret += solve(idx + 1, i, ((i == str[idx] - '0') ? flag : 0));
    return ret;
}

bool check(void)
{
    for (int i = 1; i < len; i++)
        if (str[i] < str[i - 1])
            return true;
    return false;
}

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> T;
    while (T--)
    {
        std::cin >> str;
        len = str.size();
        memset(dp, -1, sizeof(dp));
        ll ans = 0;
        if (check())
        {
            std::cout << "-1\n";
            continue ;
        }
        ans = solve(0, 0, 1) - 1;
        std::cout << ans << '\n';
    }
}