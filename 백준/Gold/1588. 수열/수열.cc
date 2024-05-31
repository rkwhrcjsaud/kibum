#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#include <cmath>

typedef long long ll;
ll start, left, right, N;
ll dp[21][4][4];
ll ans[4];

void solve(ll n, ll l, ll r, ll s)
{
    if (l > r)
        return ;
    if (l == 0 && r == std::pow(3, n) - 1)
    {
        for (int i = 1; i <= 3; i++)
            ans[i] += dp[n][s][i];
        return ;
    }
    if (n == 0)
        return ;
    ll lhalf = std::pow(3, n - 1);
    ll rhalf = std::pow(3, n - 1) * 2;
    if (l < lhalf)
    {
        int next = s == 3 ? 2 : s == 2 ? 2 : 1;
        if (r < lhalf)
            solve(n - 1, l, r, next);
        else
            solve(n - 1, l, lhalf - 1, next);
    }
    if (l < rhalf || r >= lhalf)
    {
        int next = s == 3 ? 3 : s == 2 ? 1 : 3;
        if (r >= rhalf)
        {
            if (l >= lhalf)
                solve(n - 1, l - lhalf, lhalf - 1, next);
            else
                solve(n - 1, 0, lhalf - 1, next);
        }
        else
        {
            if (l >= lhalf)
                solve(n - 1, l - lhalf, r - lhalf, next);
            else
                solve(n - 1, 0, r - lhalf, next);
        }
    }
    if (r >= rhalf)
    {
        int next = s == 3 ? 2 : s == 2 ? 1 : 2;
        if (l >= rhalf)
            solve(n - 1, l - rhalf, r - rhalf, next);
        else
            solve(n - 1, 0, r - rhalf, next);
    }
}

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> start >> left >> right >> N;
    for (int i = 1; i <= 3; i++)
        dp[0][i][i] = 1;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= 3; j++)
        {
            for (int k = 1; k <= 3; k++)
            {
                if (j == 1)
                    dp[i][1][k] = dp[i - 1][1][k] + dp[i - 1][3][k] + dp[i - 1][2][k];
                else if (j == 2)
                    dp[i][2][k] = dp[i - 1][2][k] + dp[i - 1][1][k] * 2;
                else if (j == 3)
                    dp[i][3][k] = dp[i - 1][3][k] + dp[i - 1][2][k] * 2;
            }
        }
    }
    solve(N, left, right, start);
    for (int i = 1; i <= 3; i++)
        std::cout << ans[i] << ' ';
    std::cout << '\n';
}