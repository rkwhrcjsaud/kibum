#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

int N;
std::string str;
int map[16][16];
int dp[15][10][1 << 15];

int solve(int idx, int cost, int bit)
{
    if (idx == N)
        return 0;
    if (dp[idx][cost][bit] != -1)
        return dp[idx][cost][bit];
    int ret = 0;
    for (int i = 0; i < N; i++)
    {
        if (bit & (1 << i) || map[idx][i] < cost)
            continue ;
        ret = std::max(ret, solve(i, map[idx][i], bit | (1 << i)));
    }
    return dp[idx][cost][bit] = ret + 1;
}

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N;
    for (int i = 0; i < N; i++)
    {
        int cnt = 0;
        std::cin >> str;
        for (int j = 0; j < N; j++)
            map[i][j] = str[j] - '0';
    }
    std::fill(&dp[0][0][0], &dp[14][9][1 << 15], -1);
    std::cout << solve(0, 0, 1) << '\n';
}