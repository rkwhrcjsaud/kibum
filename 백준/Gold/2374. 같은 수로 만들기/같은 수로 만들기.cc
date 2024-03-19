#include <iostream>
#include <vector>
#include <stack>

int N;
std::stack<int> s;
std::vector<int> v;

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N;
    long long ans = 0;
    for (int i = 0; i < N; i++)
    {
        long long tmp;
        std::cin >> tmp;
        v.push_back(tmp);
    }
    s.push(v[0]);
    for (int i = 1; i < N; i++)
    {
        if (s.top() > v[i])
        {
            s.push(v[i]);
        }
        else if (s.top() == v[i])
            continue ;
        else
        {
            int min = s.top();
            while (s.size() > 1 && s.top() < v[i])
                s.pop();
            ans += v[i] - min;
            if (s.top() < v[i])
                s.pop();
            s.push(v[i]);
        }
    }
    while (s.size() > 1)
    {
        int tmp = s.top();
        s.pop();
        ans += s.top() - tmp;
    }
    std::cout << ans << '\n';
}