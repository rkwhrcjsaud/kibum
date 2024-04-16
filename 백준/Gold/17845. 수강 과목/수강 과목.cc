#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

int N, K;
std::vector< std::pair<int, int> > v;
int dp[10001];

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N >> K;
    v.push_back(std::make_pair(0, 0));
    for (int i = 0; i < K; i++)
    {
        int a, b;
        std::cin >> a >> b;
        v.push_back(std::make_pair(b, a));
    }
    for (int i = 1; i <= K; i++)
    {
        for (int j = N; j >= v[i].first; j--)
        {
            dp[j] = std::max(dp[j], dp[j - v[i].first] + v[i].second);
        }
    }
    std::cout << dp[N] << '\n';
}