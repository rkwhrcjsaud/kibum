#include <iostream>
#include <vector>
#include <algorithm>

int M, N;
std::vector<int> v[100001];
int line[100001];

int solve(int y)
{
    std::vector<int> dp(N, 0);
    for (int i = 0; i < N; i++)
    {
        if (i == 0)
            dp[i] = v[y][i];
        else if (i == 1)
            dp[i] = std::max(v[y][i], v[y][i - 1]);
        else
            dp[i] = std::max(dp[i - 1], dp[i - 2] + v[y][i]);
    }
    return dp[N - 1];
}

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    while (1)
    {
        std::cin >> M >> N;
        if (M == 0 && N == 0)
            break;
        for (int i = 0; i < M; i++)
        {
            for (int j = 0; j < N; j++)
            {
                int tmp;
                std::cin >> tmp;
                v[i].push_back(tmp);
            }
        }
        line[0] = solve(0);
        for (int i = 1; i < M; i++)
        {
            if (i == 1)
                line[i] = std::max(line[i - 1], solve(i));
            else
                line[i] = std::max(line[i - 1], line[i - 2] + solve(i));
        }
        std::cout << line[M - 1] << '\n';
        for (int i = 0; i < M; i++)
            v[i].clear();
    }
}