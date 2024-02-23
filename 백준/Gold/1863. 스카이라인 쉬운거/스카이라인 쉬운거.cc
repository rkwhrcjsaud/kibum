#include <iostream>
#include <stack>

std::stack<int> s;

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    int N;
    std::cin >> N;
    int cnt = 0;
    s.push(0);
    for (int i = 0; i < N; i++)
    {
        int x, y;
        std::cin >> x >> y;
        if (s.top() < y)
            s.push(y);
        else if (s.top() > y)
        {
            while (s.top() > y)
            {
                s.pop();
                cnt++;
            }
            if (s.top() < y)
                s.push(y);
        }
    }
    std::cout << cnt + s.size() - 1 << '\n';
}