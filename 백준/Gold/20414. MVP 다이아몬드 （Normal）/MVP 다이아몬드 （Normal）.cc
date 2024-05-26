#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

int N;
int arr[5];
char change[5] = {'B', 'S', 'G', 'P', 'D'};
std::string s;
int dp[37][501];

int solve(int idx, int prev)
{
    if (idx == N)
        return 0;
    int &ret = dp[idx][prev];
    if (ret != -1)
        return ret;
    ret = -1e9;
    for (int i = 0; i <= 4; i++)
    {
        if (change[i] == s[idx])
        {
            for (int j = 0; j <= arr[4]; j++)
            {
                if (prev + j < arr[i])
                    continue ;
                if (i < 4 && prev + j >= arr[i + 1])
                    continue ;
                ret = std::max(ret, solve(idx + 1, j) + j);
            }
        }
    }
    return ret;
}

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N;
    for (int i = 1; i <= 4; i++)
        std::cin >> arr[i];
    std::cin >> s;
    memset(dp, -1, sizeof(dp));
    std::cout << solve(0, 0) << '\n';
}
