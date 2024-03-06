#include <iostream>
#include <vector>
#include <algorithm>

int N, M;
std::vector < std::pair <int, std::pair<int, int> > > v;
bool flag[500001];

int compare(std::pair <int, std::pair<int, int> > a, std::pair <int, std::pair<int, int> > b)
{
    if (a.second.first == b.second.first)
        return a.second.second > b.second.second;
    return a.second.first < b.second.first;
}

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N >> M;
    for (int i = 0; i < M; i++)
    {
        int s, e;
        std::cin >> s >> e;
        if (s > e)
            e += N;
        v.push_back(std::make_pair(i + 1, std::make_pair(s, e)));
    }
    std::sort(v.begin(), v.end(), compare);
    int start = v[0].second.first;
    int end = v[0].second.second;
    int last = v.back().second.second - N;
    if (end > last)
        flag[v[0].first] = true;
    for (int i = 1; i < M; i++)
    {
        if (v[i].second.second <= end || v[i].second.second <= last)
            continue ;
        if (v[i].second.first > start)
        {
            start = v[i].second.first;
            if (v[i].second.second > end)
                end = v[i].second.second;
            flag[v[i].first] = true;
        }
    }
    for (int i = 1; i <= M; i++)
    {
        if (flag[i])
            std::cout << i << ' ';
    }
    std::cout << '\n';
}
