#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

int N;
std::string str;
char arr[3] = {'B', 'L', 'D'};
int dp[1501][1501];

int solve(int l, int r, int day)
{
    if (l > r)
        return 0;
    int &ret = dp[l][r];
    if (ret != -1)
        return ret;
    ret = 0;
    char target = arr[day % 3];
    if (str[l] == target)
        ret = std::max(ret, solve(l + 1, r, day + 1) + 1);
    if (str[r] == target)
        ret = std::max(ret, solve(l, r - 1, day + 1) + 1);
    return ret;
}

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N >> str;
    memset(dp, -1, sizeof(dp));
    std::cout << solve(0, N * 3 - 1, 0) << '\n';
}
