#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <sstream>
#include <map>

int N, M;
int dist[1001];
int weather[1001];
int dp[1001][1001];

int solve(int city, int day)
{
    if (city == N)
        return 0;
    int &ret = dp[city][day];
    if (ret != -1)
        return ret;
    ret = 1e9;
    for (int i = 0; i < M - day; i++)
        ret = std::min(ret, solve(city + 1, day + i + 1) + dist[city] * weather[day + i]);
    return ret;
}

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N >> M;
    for (int i = 0; i < N; i++)
        std::cin >> dist[i];
    for (int i = 0; i < M; i++)
        std::cin >> weather[i];
    memset(dp, -1, sizeof(dp));
    std::cout << solve(0, 0) << '\n';
}