#include <iostream>
#include <vector>
#include <algorithm>

int N;
std::vector< std::pair<int, int> > v;

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N;
    for (int i = 0; i < N; i++)
    {
        int t, s;
        std::cin >> t >> s;
        v.push_back(std::make_pair(s, t));
    }
    std::sort(v.begin(), v.end(), std::greater< std::pair<int, int> >());
    int start = v[0].first - v[0].second;
    for (int i = 1; i < N; i++)
    {
        start = std::min(start, v[i].first);
        start -= v[i].second;
        if (start < 0)
        {
            std::cout << -1 << '\n';
            return 0;
        }
    }
    std::cout << start << '\n';
}
