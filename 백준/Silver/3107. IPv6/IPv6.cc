#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

std::vector<std::vector<char> > v(8, std::vector<char>(4, '0'));

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::string s;
    std::cin >> s;
    int col = 7;
    int row = 3;
    for (int i = s.size() - 1; i >= 0; i--)
    {
        if (s[i] == ':')
        {
            if (row == 3)
                break ;
            col--;
            row = 3;
        }
        else
        {
            v[col][row] = s[i];
            row--;
        }
    }
    col = 0;
    std::string tmp = "";
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == ':')
        {
            if (tmp == "")
                break ;
            int len = tmp.size();
            for (int j = 3; j > (3 - len); j--)
                v[col][j] = tmp[len + j - 4];
            col++;
            tmp = "";
        }
        else
            tmp += s[i];
    }
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 4; j++)
            std::cout << v[i][j];
        if (i != 7)
            std::cout << ':';
    }
}