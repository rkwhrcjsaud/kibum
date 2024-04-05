#include <iostream>
#include <stack>

std::string str;
std::stack<char> s;

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> str;
    for (int i = 0; i < str.size(); i++)
    {
        s.push(str[i]);
        while (s.size() >= 4)
        {
            char a = s.top();
            s.pop();
            char b = s.top();
            s.pop();
            char c = s.top();
            s.pop();
            char d = s.top();
            s.pop();
            if (a == 'P' && b == 'A' && c == 'P' && d == 'P')
                s.push('P');
            else
            {
                s.push(d);
                s.push(c);
                s.push(b);
                s.push(a);
                break ;
            }
        }
    }
    if (s.size() == 1 && s.top() == 'P')
        std::cout << "PPAP\n";
    else
        std::cout << "NP\n";
}