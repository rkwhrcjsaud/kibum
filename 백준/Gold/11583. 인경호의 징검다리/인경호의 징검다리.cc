#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#include <cmath>

int T, N, K;
std::vector<int> v;
int two[100001];
int five[100001];
int dp[100001][2];

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> T;
    while (T--)
    {
        std::cin >> N >> K;
        for (int i = 0; i < N; i++)
        {
            two[i] = five[i] = 0;
            int num;
            std::cin >> num;
            while (num % 2 == 0)
            {
                num /= 2;
                two[i]++;
            }
            while (num % 5 == 0)
            {
                num /= 5;
                five[i]++;
            }
        }
        for (int i = 0; i < N; i++)
            dp[i][0] = dp[i][1] = 1e9;
        int ans = 1e9;
        for (int i = 0; i <= 1; i++)
        {
            dp[0][i] = i == 0 ? two[0] : five[0];
            for (int j = 1; j < N; j++)
            {
                for (int k = std::max(0, j - K); k <= j - 1; k++)
                {
                    dp[j][i] = std::min(dp[j][i], dp[k][i] + (i == 0 ? two[j] : five[j]));
                }
            }
            ans = std::min(ans, dp[N - 1][i]);
        }
        std::cout << ans << '\n';
    }
}