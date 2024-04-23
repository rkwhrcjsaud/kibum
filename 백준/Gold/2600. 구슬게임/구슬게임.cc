#include <iostream>
#include <queue>
#include <vector>
#include <sstream>
#include <cstring>
#include <climits>

int b[3];
int K1[5], K2[5];
int dp[501][501][2];

int solve(int k1, int k2, bool flag)
{
    if (dp[k1][k2][flag] != -1)
        return dp[k1][k2][flag];
    for (int i = 0; i < 3; i++)
    {
        if (k1 >= b[i] && !solve(k1 - b[i], k2, !flag))
            return dp[k1][k2][flag] = true;
        if (k2 >= b[i] && !solve(k1, k2 - b[i], !flag))
            return dp[k1][k2][flag] = true;
    }
    return dp[k1][k2][flag] = false;
}

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> b[0] >> b[1] >> b[2];
    memset(dp, -1, sizeof(dp));
    for (int i = 0; i < 5; i++)
    {
        int k1, k2;
        std::cin >> k1 >> k2;
        if (solve(k1, k2, false))
            std::cout << "A\n";
        else
            std::cout << "B\n";
    }
}