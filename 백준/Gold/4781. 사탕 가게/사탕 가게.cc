#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

int trans(void)
{
    std::string tmp;
    std::cin >> tmp;
    int ret = 0;
    for (int i = 0; i < tmp.size(); ++i)
    {
        if (tmp[i] == '.')
            continue ;
        ret *= 10;
        ret += tmp[i] - '0';
    }
    return ret;
}

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    while (1)
    {
        int N, M;
        std::cin >> N;
        M = trans();
        if (N == 0 && M == 0)
            break ;
        std::vector< std::pair<int, int> > candy;
        for (int i = 0; i < N; ++i)
        {
            int tmp1, tmp2;
            std::cin >> tmp1;
            tmp2 = trans();
            candy.push_back(std::make_pair(tmp1, tmp2));
        }
        std::vector<int> dp(M + 1, 0);
        for (int i = 0; i < N; ++i)
        {
            for (int j = candy[i].second; j <= M; ++j)
            {
                dp[j] = std::max(dp[j], dp[j - candy[i].second] + candy[i].first);
            }
        }
        std::cout << dp[M] << '\n';
    }
}