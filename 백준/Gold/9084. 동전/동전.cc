#include <iostream>
#include <vector>

int T, N;


int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> T;
    while (T--)
    {
        int N, M;
        std::cin >> N;
        std::vector<int> v;
        for (int i = 0; i < N; i++)
        {
            int tmp;
            std::cin >> tmp;
            v.push_back(tmp);
        }
        std::cin >> M;
        int dp[10001] = {0, };
        dp[0] = 1;
        for (int i = 0; i < N; i++)
        {
            for (int j = v[i]; j <= M; j++)
                dp[j] += dp[j - v[i]];
        }
        std::cout << dp[M] << '\n';
    }
}