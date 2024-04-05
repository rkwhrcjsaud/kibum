#include <iostream>
#include <string>
#include <algorithm>

std::string S, T;

bool solve(std::string str)
{
    bool flag = false;
    if (str.size() == S.size())
        return str == S;
    if (str.back() == 'A')
        flag = solve(str.substr(0, str.size() - 1));
    if (str.front() == 'B' && !flag)
    {
        std::string tmp = str.substr(1, str.size());
        std::reverse(tmp.begin(), tmp.end());
        flag = solve(tmp);
    }
    return flag;
}

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> S >> T;
    std::cout << solve(T) ? 1 : 0 << '\n';
}