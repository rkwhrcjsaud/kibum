#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <sstream>
#include <map>
#include <queue>
#include <cmath>

int P, Q;
int arr[110];
int dp[110][110];

int solve(int l, int r)
{
    if (l + 1 == r)
        return 0;
    int &ret = dp[l][r];
    if (ret != -1)
        return ret;
    ret = 1e9;
    for (int i = l + 1; i < r; i++)
        ret = std::min(ret, solve(l, i) + solve(i, r) + arr[r] - arr[l] - 2);
    return ret;
}

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> P >> Q;
    for (int i = 1; i <= Q; i++)
        std::cin >> arr[i];
    arr[Q + 1] = P + 1;
    std::sort(arr + 1, arr + Q + 1);
    memset(dp, -1, sizeof(dp));
    std::cout << solve(0, Q + 1) << '\n';
}