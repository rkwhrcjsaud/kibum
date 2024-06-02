#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#include <cmath>

int N, M;
int arr[2001];
int dp[2001][1001];
int A, D;

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N >> M;
    memset(dp, -1, sizeof(dp));
    for (int i = 1; i <= N; i++)
        std::cin >> arr[i];
    std::cin >> A >> D;
    dp[0][0] = 0;
    for (int i = 1; i <= N + D - 1; i++)
    {
        for (int j = 0; j <= N; j++)
        {
            if (dp[i - 1][j] != -1)
                dp[i][j] = dp[i - 1][j] + arr[i];
            if (j > 0 && i - D >= 0 && dp[i - D][j - 1] != -1)
                dp[i][j] = std::max(dp[i][j], dp[i - D][j - 1] + A);
        }
    }
    for (int i = 0; i <= N; i++)
    {
        if (dp[N + D - 1][i] >= M)
        {
            std::cout << i << '\n';
            return 0;
        }
    }
    std::cout << "-1\n";
}