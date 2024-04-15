#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

std::string A, B;
int dp[1001][1001];

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> A >> B;
    A = ' ' + A;
    B = ' ' + B;
    int n = A.size(), m = B.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i == 0 && j == 0)
                continue;
            if (i == 0)
            {
                dp[i][j] = j;
                continue;
            }
            if (j == 0)
            {
                dp[i][j] = i;
                continue;
            }
            if (A[i] == B[j])
                dp[i][j] = dp[i - 1][j - 1];
            else
                dp[i][j] = std::min(dp[i - 1][j - 1], std::min(dp[i - 1][j], dp[i][j - 1])) + 1;
        }
    }
    std::cout << dp[n - 1][m - 1] << '\n';
}