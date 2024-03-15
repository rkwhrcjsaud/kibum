#include <iostream>
#include <deque>

std::deque<int> dq;

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::string str;
    std::cin >> str;
    int ans = 0;
    for (int i = (int)str.length() - 1; i >= 0; i--)
    {
        if (str[i] == 'B')
            dq.push_front(i);
        else if (str[i] == 'A')
        {
            if (!dq.empty())
            {
                ans++;
                dq.pop_back();
            }
        }
    }
    for (int i = (int)str.length() - 1; i >= 0; i--)
    {
        if (str[i] == 'A' || str[i] == 'B')
            continue ;
        while (!dq.empty() && dq.back() > i)
            dq.pop_back();
        if (!dq.empty())
        {
            ans++;
            dq.pop_back();
        }
    }
    std::cout << ans << '\n';
}