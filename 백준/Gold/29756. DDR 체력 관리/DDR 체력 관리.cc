#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

int N, K;
int point[1001];
int damage[1001];
int dp[1001][101];

int solve(int idx, int hp)
{
    if (idx == N)
        return 0;
    if (hp > 100)
        hp = 100;
    int &ret = dp[idx][hp];
    if (ret != -1)
        return ret;
    ret = 0;
    if (hp >= damage[idx])
        ret = std::max(ret, solve(idx + 1, hp - damage[idx] + K) + point[idx]);
    ret = std::max(ret, solve(idx + 1, hp + K));
    return ret;
}

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N >> K;
    for (int i = 0; i < N; i++)
        std::cin >> point[i];
    for (int i = 0; i < N; i++)
        std::cin >> damage[i];
    memset(dp, -1, sizeof(dp));
    std::cout << solve(0, 100) << '\n';
}
