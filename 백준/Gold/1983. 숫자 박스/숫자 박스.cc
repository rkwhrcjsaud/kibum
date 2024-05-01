#include <iostream>
#include <vector>
#include <algorithm>

int N;
int arr[401][2];
int len[2];
int dp[401][401][401];

int solve(int i, int j, int k)
{
    if (i == len[0] || j == len[1])
        return 0;
    int &ret = dp[i][j][k];
    if (ret != -40000)
        return ret;
    ret = -40000;
    if (len[0] - i + k < N)
        ret = std::max(ret, solve(i, j + 1, k + 1));
    if (len[1] - j + k < N)
        ret = std::max(ret, solve(i + 1, j, k + 1));
    return ret = std::max(ret, solve(i + 1, j + 1, k + 1) + arr[i][0] * arr[j][1]);
}

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < N; j++)
        {
            std::cin >> arr[len[i]][i];
            if (arr[len[i]][i])
                len[i]++;
        }
    }
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            for (int k = 0; k < N; k++)
                dp[i][j][k] = -40000;
    std::cout << solve(0, 0, 0) << std::endl;
}