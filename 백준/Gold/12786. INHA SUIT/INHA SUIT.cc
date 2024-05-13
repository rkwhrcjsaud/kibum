#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

int N, K;
std::vector<int> arr[101];
int dp[101][51][21];

int solve(int idx, int k, int t)
{
    if (idx == N)
        return 1;
    int &ret = dp[idx][k][t];
    if (ret != -1)
        return ret;
    ret = 0;
    for (int i = 0; i < arr[idx].size(); i++)
    {
        if (k != 0)
            ret |= solve(idx + 1, k - 1, arr[idx][i]);
        if (t + 1 == arr[idx][i])
            ret |= solve(idx + 1, k, t + 1);
        else if (t * 2 == arr[idx][i])
            ret |= solve(idx + 1, k, t * 2);
        else if (t >= 10 && arr[idx][i] == 20)
            ret |= solve(idx + 1, k, 20);
        else if (t - 1 == arr[idx][i])
            ret |= solve(idx + 1, k, t - 1);
        else if (t == arr[idx][i])
            ret |= solve(idx + 1, k, t);
    }
    return ret;
}

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N >> K;
    for (int i = 0; i < N; i++)
    {
        int M;
        std::cin >> M;
        arr[i].resize(M);
        for (int j = 0; j < M; j++)
            std::cin >> arr[i][j];
    }
    memset(dp, -1, sizeof(dp));
    for (int i = 0; i <= K; i++)
    {
        if (solve(0, i, 1))
        {
            std::cout << i << '\n';
            return 0;
        }
    }
    std::cout << -1 << '\n';
}
