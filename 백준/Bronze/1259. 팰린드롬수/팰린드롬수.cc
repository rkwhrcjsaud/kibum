#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

string s;

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    while (cin >> s)
    {
        if (s == "0")
            break ;
        bool flag = true;
        for (int i = 0; i < s.size() / 2; i++)
        {
            if (s[i] != s[s.size() - i - 1])
            {
                flag = false;
                break ;
            }
        }
        if (flag)
            cout << "yes\n";
        else
            cout << "no\n";
    }
}