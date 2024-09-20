#include <iostream>
#include <string>
#include <stack>

using namespace std;

stack<char> s;
string ans = "";

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    string str;
    cin >> str;
    for (int i = 0; i < str.size(); i++)
    {
        if (isalpha(str[i]))
            ans += str[i];
        else if (str[i] == '(')
            s.push(str[i]);
        else if (str[i] == '*' || str[i] == '/')
        {
            while (!s.empty() && (s.top() == '*' || s.top() == '/'))
            {
                ans += s.top();
                s.pop();
            }
            s.push(str[i]);
        }
        else if (str[i] == '+' || str[i] == '-')
        {
            while (!s.empty() && s.top() != '(')
            {
                ans += s.top();
                s.pop();
            }
            s.push(str[i]);
        }
        else if (str[i] == ')')
        {
            while (!s.empty() && s.top() != '(')
            {
                ans += s.top();
                s.pop();
            }
            s.pop();
        }
    }
    while (!s.empty())
    {
        ans += s.top();
        s.pop();
    }
    cout << ans << '\n';
}