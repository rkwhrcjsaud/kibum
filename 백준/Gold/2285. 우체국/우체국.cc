#include <iostream>
#include <vector>
#include <algorithm>

int N;
std::vector<std::pair<int, int> > v;

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N;
    long long total = 0;
    for (int i = 0; i < N; i++)
    {
        int x, a;
        std::cin >> x >> a;
        total += a;
        v.push_back(std::make_pair(x, a));
    }
    std::sort(v.begin(), v.end());
    long long mid = (total + 1) / 2;
    long long tmp = 0;
    int ans = 0;
    for (int i = 0; i < N; i++)
    {
        tmp += v[i].second;
        if (tmp >= mid)
        {
            ans = v[i].first;
            break ;
        }
    }
    std::cout << ans << '\n';
}