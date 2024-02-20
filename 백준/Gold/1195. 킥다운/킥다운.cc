#include <iostream>

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::string str1, str2;
    std::cin >> str1 >> str2;
    if (str1.size() > str2.size())
    {
        std::string tmp = str1;
        str1 = str2;
        str2 = tmp;
    }
    std::string emptystr(str1.size(), '0');
    str2 = emptystr + str2 + emptystr;
    int min = str2.size() - str1.size();
    for (int i = 0; i <= str2.size() - str1.size(); i++)
    {
        int len = str2.size() - str1.size() * 2;
        if (i < str1.size())
            len = str2.size() - str1.size() - i;
        else if (i > str2.size() - str1.size() * 2)
            len = i;
        for (int j = 0; j < str1.size(); j++)
        {
            if (str1[j] == str2[i + j] && str1[j] == '2')
            {
                len = str2.size() - str1.size();
                break;
            }
        }
        min = min < len ? min : len;
    }
    std::cout << min << '\n';
}