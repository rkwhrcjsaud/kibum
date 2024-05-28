#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <map>

int N;
std::string s;
int dp[1000001][5];
char word[5] = {' ', 'R', 'O', 'C', 'K'};
const int MOD = 1e9 + 7;

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N >> s;
    dp[0][0] = 2;
    dp[0][1] = (s[0] == 'R');
    for (int i = 1; i < N; i++)
    {
        dp[i][0] = dp[i - 1][0] * 2;
        dp[i][0] %= MOD;
        for (int j = 1; j < 5; j++)
        {
            if (s[i] == word[j])
            {
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
                dp[i][j] %= MOD;
            }
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    std::cout << dp[N - 1][4] << '\n';
}