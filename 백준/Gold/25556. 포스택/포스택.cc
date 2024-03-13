#include <iostream>
#include <stack>
#include <deque>

std::stack<int> s[4];
std::deque<int> dq;

int N;

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N;
    for (int i = 0; i < N; i++)
    {
        int tmp;
        std::cin >> tmp;
        dq.push_back(tmp);
    }
    while (!dq.empty())
    {
        int idx = 5;
        int top = 0;
        for (int i = 0; i < 4; i++)
        {
            if (s[i].empty())
            {
                idx = i;
                break ;
            }
            else if (s[i].top() < dq.front() && top < s[i].top())
            {
                idx = i;
                top = s[i].top();
                break ;
            }
        }
        if (idx == 5)
        {
            std::cout << "NO\n";
            return 0;
        }
        s[idx].push(dq.front());
        dq.pop_front();
    }
    std::cout << "YES\n";
}