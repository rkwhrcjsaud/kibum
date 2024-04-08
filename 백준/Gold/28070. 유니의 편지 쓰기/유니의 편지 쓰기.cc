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
    for (int i = 0; i < N; i++)
    {
        int y, m;
        char c;
        std::cin >> y >> c >> m;
        v.push_back(std::make_pair((y << 4) | m, 1));
        std::cin >> y >> c >> m;
        v.push_back(std::make_pair((y << 4) | m, -1));
    }
    std::sort(v.begin(), v.end());
    int cnt = 0, max = 0, ans = 0;
    for (int i = 0; i < v.size(); i++)
    {
        int minus = 0;
        if (v[i].second == -1)
            minus++;
        else
            cnt++;
        while (i < v.size() && v[i].first == v[i + 1].first)
        {
            if (v[i + 1].second == -1)
                minus++;
            else
                cnt++;
            i++;
        }
        if (max < cnt)
        {
            max = cnt;
            ans = v[i].first;
        }
        cnt -= minus;
    }
    std::string m = std::to_string(ans & 15);
    if (m.size() == 1)
        m = '0' + m;
    std::cout << ans / 16 << '-' << m << '\n';
}