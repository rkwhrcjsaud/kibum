#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>

int T;
std::string s;
int size;
bool isSuccess;

bool solve(int bit)
{
    if (bit == (1 << size) - 1 || isSuccess)
    {
        isSuccess = true;
        return true;
    }
    bool ret = false;
    for (int i = 0; i < size; i++)
    {
        if (bit & (1 << i))
            continue ;
        int tmp = (1 << i);
        bool flag = false;
        for (int j = i + 1; j < size; j++)
        {
            if (bit & (1 << j))
                continue;
            if (s[i] == s[j])
            {
                tmp |= (1 << j);
                flag = true;
            }
            else
            {
                i = j - 1;
                break ;
            }
        }
        if (flag)
            ret |= solve(bit | tmp);
    }
    return ret;
}

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> T;
    while (T--)
    {
        std::cin >> s;
        size = s.size();
        isSuccess = false;
        std::cout << (solve(0) ? 1 : 0) << '\n';
    }
}
