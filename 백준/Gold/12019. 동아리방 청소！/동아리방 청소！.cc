#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <sstream>
#include <map>

int N, M;
int man[101];
int dp[101][101][2001];

int solve(int day, int m, int sum)
{
    if (day == N)
        return 0;
    int &ret = dp[day][m][sum];
    if (ret != -1)
        return ret;
    ret = 1e9;
    if (m > 0)
        ret = solve(day + 1, m - 1, man[day]);
    ret = std::min(ret, solve(day + 1, m, sum + man[day]) + man[day] * sum);
    return ret;
}

void find(int day, int m, int sum)
{
    if (day == N || m == 0)
        return;
    if (solve(day, m, sum) == solve(day + 1, m - 1, man[day]))
    {
        std::cout << day << ' ';
        find(day + 1, m - 1, man[day]);
    }
    else if (solve(day, m, sum) == solve(day + 1, m, sum + man[day]) + man[day] * sum)
        find(day + 1, m, sum + man[day]);
}

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N >> M;
    for (int i = 0; i < N; i++)
        std::cin >> man[i];
    memset(dp, -1, sizeof(dp));
    std::cout << solve(0, M, 0) << '\n';
    find(0, M, 0);
    std::cout << '\n';
}