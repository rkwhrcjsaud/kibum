#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

int T, N;
std::vector<std::pair<int, int> > v;
int dp[101][10001];

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> T >> N;
    for (int i = 0; i < N; ++i)
    {
        int a, b;
        std::cin >> a >> b;
        v.push_back(std::make_pair(a, b));
    }
    dp[0][0] = 1;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j <= T; ++j)
        {
            for (int k = 0; k <= v[i].second; ++k)
            {
                if (j + v[i].first * k > T)
                    break;
                dp[i + 1][j + v[i].first * k] += dp[i][j];
            }
        }
    }
    std::cout << dp[N][T] << '\n';
}