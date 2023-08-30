#include <iostream>
#include <set>

#define MIN(a, b) (a > b ? b : a)

int n, m;
int min;
std::set <int> s;

void    force(int c, int cnt)
{
    c *= 10;
    if (c > n && abs(c - n) > min)
        return ;
    std::set<int>::iterator iter = s.begin();
    while (iter != s.end())
    {
        int t = c + *iter;
        min = MIN(min, abs(t - n) + cnt);
        if (t != 0)
            force(t, cnt + 1);
        iter++;
    }
}

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> n >> m;
    min = abs(n - 100);
    int i = 0;
    while (i < 10)
        s.insert(i++);
    i = 0;
    while (i++ < m)
    {
        int temp;
        std::cin >> temp;
        s.erase(temp);
    }
    force(0, 1);
    std::cout << min << "\n";
}