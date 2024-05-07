#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

int N;
int arr[10];
typedef long long ll;
ll dp[11][11][11][11][11][6][6];

ll solve(int a, int b, int c, int d, int e, int prev, int prev2)
{
    if (prev == prev2 && prev != 0)
        return 0;
    if (a < 0 || b < 0 || c < 0 || d < 0 || e < 0)
        return 0;
    if (a == 0 && b == 0 && c == 0 && d == 0 && e == 0)
        return 1;
    ll &ret = dp[a][b][c][d][e][prev][prev2];
    if (ret != -1)
        return ret;
    ret = 0;
    if (a > 0 && 1 != prev2)
        ret += solve(a - 1, b, c, d, e, 1, prev);
    if (b > 0 && 2 != prev2)
        ret += solve(a, b - 1, c, d, e, 2, prev);
    if (c > 0 && 3 != prev2)
        ret += solve(a, b, c - 1, d, e, 3, prev);
    if (d > 0 && 4 != prev2)
        ret += solve(a, b, c, d - 1, e, 4, prev);
    if (e > 0 && 5 != prev2)
        ret += solve(a, b, c, d, e - 1, 5, prev);
    return ret;
}

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N;
    for (int i = 1; i <= N; i++)
        std::cin >> arr[i];
    memset(dp, -1, sizeof(dp));
    std::cout << solve(arr[1], arr[2], arr[3], arr[4], arr[5], 0, 0) << '\n';
}