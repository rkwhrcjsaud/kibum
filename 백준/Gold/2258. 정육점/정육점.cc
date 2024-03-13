#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

int N, M;
std::vector<std::pair<int, int> > v;


int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        int w, m;
        std::cin >> w >> m;
        v.push_back(std::make_pair(m, -w));
    }
    std::sort(v.begin(), v.end());
    long long ans = __LONG_LONG_MAX__;
    int weight = 0;
    for (int i = 0; i < N;)
    {
        int m = v[i].first;
        int tmp = 0;
        for (; i < N && v[i].first == m; i++)
        {
            weight -= v[i].second;
            tmp += m;
            if (weight >= M && ans > tmp)
                ans = tmp;
        }
    }
    if (ans == __LONG_LONG_MAX__)
        ans = -1;
    std::cout << ans << '\n';
}