#include <iostream>

std::string str;
std::string ans;

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> str;
    int num = 0;
    for (int i = 0; i < str.size(); i++)
    {
        if (std::isdigit(str[i]))
            num = num * 10 + (str[i] - '0');
        else
        {
            if (num != 0)
            {
                if (num != 2)
                    ans += std::to_string(num / 2);
                num = 0;
            }
            if (str[i] == 'x')
                ans += "xx";
            else
                ans += str[i];
        }
    }
    if (num != 0)
    {
        if (num != 1)
            ans += std::to_string(num);
        ans += "x";
    }
    if (str != "0")
        ans += "+";
    ans += "W";
    std::cout << ans << '\n';
}