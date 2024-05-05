#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

int N, M, K;
int dp[12][222][222];

int solve(int idx, int num, int min)
{
    if (N < idx || M < num)
        return 0;
    int &ret = dp[idx][num][min];
    if (ret != -1)
        return ret;
    ret = 0;
    for (int i = min; i <= M; i++)
    {
        if (i + num > M)
            break;
        ret += solve(idx + 1, num + i, i);
    }
    return ret;
}

void print(int idx, int num, int min, int k)
{
    if (idx == N)
        return;
    for (int i = min; i <= M; i++)
    {
        if (dp[idx + 1][num + i][i] == -1)
            continue ;
        if (dp[idx + 1][num + i][i] < k)
        {
            k -= dp[idx + 1][num + i][i];
            continue ;
        }
        std::cout << i << ' ';
        print(idx + 1, num + i, i, k);
        return ;
    }
}

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N >> M >> K;
    memset(dp, -1, sizeof(dp));
    for (int i = 1; i <= M; i++)
        dp[N][M][i] = 1;
    solve(0, 0, 1);
    print(0, 0, 1, K);
    std::cout << '\n';
}
