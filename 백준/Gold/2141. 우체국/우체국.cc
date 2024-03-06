#include <iostream>
#include <vector>
#include <algorithm>

int N;
std::vector< std::pair<int, long long> > v;
std::vector< std::pair<int, long long> > v2;

int search(int start, int end, long long mid)
{
    if (start == end)
        return start;
    int mid2 = (start + end) / 2;
    if (v2[mid2].second < mid)
        return search(mid2 + 1, end, mid);
    else
        return search(start, mid2, mid);
}

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N;
    for (int i = 0; i < N; i++)
    {
        int x, a;
        std::cin >> x >> a;
        v.push_back(std::make_pair(x, a));
    }
    std::sort(v.begin(), v.end());
    for (int i = 0; i < N; i++)
    {
        if (v2.empty())
            v2.push_back(v[i]);
        else
            v2.push_back(std::make_pair(v[i].first, v2.back().second + v[i].second));
    }
    long long mid = (v2.back().second + 1) / 2;
    int idx = search(0, N - 1, mid);
    while (v2[idx].second < mid)
        idx++;
    std::cout << v2[idx].first << '\n';
}