#include <iostream>
#include <deque>

std::deque<char> dq;

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::string str;
    std::cin >> str;
    int ans = 0;
    dq.push_back(str[0]);
    for (int i = 1; i < (int)str.length(); i++)
    {
        char left = dq.front();
        if (left >= str[i])
            dq.push_front(str[i]);
        else
            dq.push_back(str[i]);
    }
    while (!dq.empty())
    {
        std::cout << dq.front();
        dq.pop_front();
    }
    std::cout << '\n';
}