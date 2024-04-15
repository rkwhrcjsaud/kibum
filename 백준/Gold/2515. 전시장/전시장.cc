#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

int N, S;
std::vector< std::pair<int, int> > v;
int dp[300001];

int compare(const std::pair<int, int> &a, const std::pair<int, int> &b)
{
    if (a.first == b.first)
        return a.second > b.second;
    return a.first < b.first;
}

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N >> S;
    v.push_back(std::make_pair(0, 0));
    for (int i = 0; i < N; i++)
    {
        int a, b;
        std::cin >> a >> b;
        v.push_back(std::make_pair(a, b));
    }
    std::sort(v.begin(), v.end(), compare);
    int idx = 0;
    for (int i = 1; i <= N; i++)
    {
        while (idx + 1 < i && v[i].first - v[idx + 1].first >= S)
            idx++;
        dp[i] = std::max(dp[i - 1], dp[idx] + v[i].second);
    }
    std::cout << dp[N] << '\n';
}