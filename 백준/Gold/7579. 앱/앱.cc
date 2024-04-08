#include <iostream>
#include <vector>

int N, M;
std::vector<int> v;
std::vector<int> w;
int dp[101][10001];

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        int tmp;
        std::cin >> tmp;
        v.push_back(tmp);
    }
    for (int i = 0; i < N; i++)
    {
        int tmp;
        std::cin >> tmp;
        w.push_back(tmp);
    }
    for (int i = 1; i <= N; i++)
    {
        for (int j = 0; j <= 10000; j++)
        {
            if (j < w[i - 1])
                dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] = std::max(dp[i - 1][j], dp[i - 1][j - w[i - 1]] + v[i - 1]);
        }
    }
    for (int i = 0; i <= 10000; i++)
    {
        if (dp[N][i] >= M)
        {
            std::cout << i << '\n';
            break ;
        }
    }
}