#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

int N;
std::string s;
const int MOD = 1e9 + 7;
char arr[4] = {'W', 'H', 'E', 'E'};
int dp[200001][4];
// j = 0 : W
// j = 1 : WH
// j = 3 : WHE
// j = 4 : WHEE...

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N >> s;
    dp[0][0] = s[0] == 'W' ? 1 : 0;
    for (int i = 1; i < N; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (s[i] == arr[j])
            {
                if (j == 0)
                    dp[i][j] = (dp[i - 1][j] + 1) % MOD;
                else
                    dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - 1]) % MOD;
                if (j == 3)
                {
                    dp[i][j] += dp[i - 1][j];
                    dp[i][j] %= MOD;
                }
            }
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    std::cout << dp[N - 1][3] << '\n';
}
