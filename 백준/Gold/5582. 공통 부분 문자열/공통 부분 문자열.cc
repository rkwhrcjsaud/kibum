#include <iostream>
#include <queue>
#include <vector>

std::string s1, s2;
int dp[4001][4001];

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> s1 >> s2;
    int max = 0;
    for (int i = 0; i < s1.size(); i++)
    {
        for (int j = 0; j < s2.size(); j++)
        {
            if (s1[i] == s2[j])
            {
                if (i == 0 || j == 0)
                    dp[i][j] = 1;
                else
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                max = std::max(max, dp[i][j]);
            }
        }
    }
    std::cout << max << '\n';
}