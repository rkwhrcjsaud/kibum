#include <iostream>
#include <vector>
#include <algorithm>

int N, M;
int arr[10001];
int dp[10001][201];

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N >> M;
    for (int i = 1; i <= N; i++)
        arr[i] = 1;
    for (int i = 0; i < M; i++)
    {
        int tmp;
        std::cin >> tmp;
        arr[tmp] = 0;
    }
    std::fill(&dp[0][0], &dp[10000][201], 1e9);
    dp[1][0] = 0;
    for (int i = 2; i <= N; i++)
    {
        if (arr[i] == 0)
            continue;
        for (int j = 1; j < std::min(i, 200); j++)
        {
            dp[i][j] = std::min(dp[i - j][j - 1], std::min(dp[i - j][j], dp[i - j][j + 1])) + 1;
        }
    }
    int result = 1e9;
    for (int i = 1; i <= 200; i++)
        result = std::min(result, dp[N][i]);
    if (result == 1e9)
        result = -1;
    std::cout << result << '\n';
}