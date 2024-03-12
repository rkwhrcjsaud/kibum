#include <iostream>
#include <vector>
#include <algorithm>

int N, M;
int dp[1010][1010];
std::vector<int> man;
std::vector<int> woman;

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        int m;
        std::cin >> m;
        man.push_back(m);
    }
    for (int i = 0; i < M; i++)
    {
        int w;
        std::cin >> w;
        woman.push_back(w);
    }
    std::sort(man.begin(), man.end());
    std::sort(woman.begin(), woman.end());
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            if (i == j)
                dp[i][j] = dp[i - 1][j - 1] + std::abs(man[i - 1] - woman[j - 1]);
            else if (i > j)
                dp[i][j] = std::min(dp[i - 1][j], dp[i - 1][j - 1] + std::abs(man[i - 1] - woman[j - 1]));
            else
                dp[i][j] = std::min(dp[i][j - 1], dp[i - 1][j - 1] + std::abs(man[i - 1] - woman[j - 1]));
        }
    }
    std::cout << dp[N][M] << '\n';
}