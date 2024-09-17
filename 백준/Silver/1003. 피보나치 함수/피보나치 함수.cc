#include <iostream>
#include <string>
#include <string.h>

int T, N;
std::pair<int, int> dp[41];

std::pair<int, int> sol(int n)
{
    std::pair<int, int> &ret = dp[n];
    if (ret.first != -1)
        return ret;
    if (n == 0)
        return ret = std::make_pair(1, 0);
    if (n == 1)
        return ret = std::make_pair(0, 1);
    return ret = std::make_pair(sol(n - 1).first + sol(n - 2).first, sol(n - 1).second + sol(n - 2).second);
}

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> T;
    for (int i = 0; i < 41; i++)
        dp[i] = std::make_pair(-1, -1);
    while (T--)
    {
        std::cin >> N;
        std::pair<int, int> ans = sol(N);
        std::cout << ans.first << ' ' << ans.second << '\n';
    }
}