#include <iostream>

int N;
std::string str;
int dp[1000001][2];

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N >> str;
    if (str[0] == 'A')
        dp[0][1] = 1;
    else
        dp[0][0] = 1;
    for (int i = 1; i < N; i++)
    {
        if (str[i] == 'A')
        {
            dp[i][0] = std::min(dp[i - 1][0], dp[i - 1][1] + 1);
            dp[i][1] = std::min(dp[i - 1][0] + 1, dp[i - 1][1] + 1);
        }
        else
        {
            dp[i][0] = std::min(dp[i - 1][0] + 1, dp[i - 1][1] + 1);
            dp[i][1] = std::min(dp[i - 1][0] + 1, dp[i - 1][1]);
        }
    }
    std::cout << dp[N - 1][0] << '\n';
}