#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <sstream>
#include <map>
#include <queue>
#include <cmath>

int N;
typedef long long ll;
ll dp[2001][2001];
ll a[2001];
ll b[2001];
int B, E;
ll max = -1e18;

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N;
    for (int i = 0; i < N; i++)
        std::cin >> a[i];
    for (int i = 0; i < N; i++)
        std::cin >> b[i];
    for (int i = 0; i < N; i++)
    {
        dp[i][i] = a[i] * b[i];
        if (dp[i][i] > max)
        {
            max = dp[i][i];
            B = i;
            E = i;
        }
        for (int j = 1; i + j < N && i - j >= 0; j++)
        {
            dp[i - j][i + j] = dp[i - j + 1][i + j - 1] + a[i - j] * b[i + j] + a[i + j] * b[i - j];
            if (dp[i - j][i + j] > max)
            {
                max = dp[i - j][i + j];
                B = i - j;
                E = i + j;
            }
        }
    }
    for (int i = 0; i < N - 1; i++)
    {
        dp[i][i + 1] = a[i] * b[i + 1] + a[i + 1] * b[i];
        if (dp[i][i + 1] > max)
        {
            max = dp[i][i + 1];
            B = i;
            E = i + 1;
        }
        for (int j = 1; i + j + 1 < N && i - j >= 0; j++)
        {
            dp[i - j][i + j + 1] = dp[i - j + 1][i + j] + a[i - j] * b[i + j + 1] + a[i + j + 1] * b[i - j];
            if (dp[i - j][i + j + 1] > max)
            {
                max = dp[i - j][i + j + 1];
                B = i - j;
                E = i + j + 1;
            }
        }
    }
    std::cout << B << ' ' << N - E - 1 << '\n';
    std::cout << max << '\n';
}
