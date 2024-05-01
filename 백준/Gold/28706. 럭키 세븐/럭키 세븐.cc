#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

int T, N;
std::vector<std::pair<int, int> > v;

bool solve(int idx, int bit)
{
    if (idx == N)
        return (bit & 1);
    int next = 0;
    for (int i = 0; i < 7; i++)
    {
        if (!(bit & (1 << i)))
            continue ;
        int a, b;
        if (v[idx].first > 0)
            a = v[idx].first + i;
        else
            a = -v[idx].first * i;
        if (v[idx].second > 0)
            b = v[idx].second + i;
        else
            b = -v[idx].second * i;
        a %= 7;
        b %= 7;
        next |= (1 << a);
        next |= (1 << b);
    }
    return solve(idx + 1, next);
}

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> T;
    while (T--)
    {
        std::cin >> N;
        v.clear();
        for (int i = 0; i < N; i++)
        {
            int a, b;
            char c, d;
            std::cin >> c >> a >> d >> b;
            if (c == '*') a = -a;
            if (d == '*') b = -b;
            v.push_back(std::make_pair(a, b));
        }
        std::cout << (solve(0, 2) ? "LUCKY" : "UNLUCKY") << '\n';
    }
}
