#include <iostream>
#include <queue>
#include <algorithm>

int N;
std::priority_queue<int> plus;
std::priority_queue<int, std::vector<int>, std::greater<int> > minus;

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N;
    for (int i = 0; i < N; i++)
    {
        int tmp;
        std::cin >> tmp;
        if (tmp > 0)
            plus.push(tmp);
        else
            minus.push(tmp);
    }
    long long ans = 0;
    while (!plus.empty())
    {
        long long i = plus.top();
        plus.pop();
        if (plus.empty())
        {
            ans += i;
            break ;
        }
        long long j = plus.top();
        plus.pop();
        if (i == 1 || j == 1)
        {
            ans += i + j;
            continue ;
        }
        ans += i * j;
    }
    while (!minus.empty())
    {
        long long i = minus.top();
        minus.pop();
        if (minus.empty())
        {
            ans += i;
            break ;
        }
        long long j = minus.top();
        minus.pop();
        ans += i * j;
    }
    std::cout << ans << '\n';
}