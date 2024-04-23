#include <iostream>
#include <queue>
#include <vector>
#include <sstream>
#include <cstring>
#include <climits>

int R, C;
int apple[1510][1510], banana[1510][1510];
int dp[1510][1510];

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> R >> C;
    for (int i = 1; i <= R; i++)
    {
        for (int j = 1; j <= C; j++)
        {
            std::string str;
            std::cin >> str;
            std::stringstream ss(str.substr(1));
            int num;
            ss >> num;
            if (str[0] == 'A')
                apple[i][j] = num;
            else
                banana[i][j] = num;
        }
    }
    for (int i = 1; i <= R; i++)
    {
        for (int j = 1; j <= C; j++)
        {
            apple[i][j] += apple[i - 1][j];
            banana[i][j] += banana[i - 1][j];
        }
    }
    for (int i = 1; i <= R; i++)
    {
        for (int j = 1; j <= C; j++)
        {
            if (j == 1)
                dp[i][j] = apple[R][1] - apple[i][j];
            else
            {
                int a = apple[R][j] - apple[i][j] + banana[i - 1][j];
                dp[i][j] = std::max(dp[i - 1][j - 1] + a, std::max(dp[i][j - 1] + a, dp[i - 1][j] - apple[i][j] + apple[i - 1][j]));
            } 
        }
    }
    std::cout << dp[R][C] << '\n';
}