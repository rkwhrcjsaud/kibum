#include <iostream>
#include <vector>
#include <queue>

int N, K;
std::vector<int> v;
long long dp[16][1 << 16];

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N >> K;
    for (int i = 0; i < N; i++)
    {
        int t;
        std::cin >> t;
        v.push_back(t);
    }
    std::queue< std::pair<int, int> > q;
    for (int i = 0; i < N; i++)
    {
        q.push(std::make_pair(i, 1 << i));
        dp[i][1 << i] = 1;
    }
    while (!q.empty())
    {
        int cur = q.front().first;
        int bit = q.front().second;
        q.pop();
        for (int i = 0; i < N; i++)
        {
            if (bit & (1 << i))
                continue ;
            if (std::abs(v[cur] - v[i]) <= K)
                continue ;
            if (dp[i][bit | (1 << i)] == 0)
                q.push(std::make_pair(i, bit | (1 << i)));
            dp[i][bit | (1 << i)] += dp[cur][bit];
        }
    }
    long long ans = 0;
    for (int i = 0; i < N; i++)
        ans += dp[i][(1 << N) - 1];
    std::cout << ans << '\n';
}
