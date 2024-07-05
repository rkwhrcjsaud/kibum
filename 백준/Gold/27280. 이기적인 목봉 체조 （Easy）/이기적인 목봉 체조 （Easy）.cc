#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <sstream>
#include <map>
#include <queue>
#include <cmath>

int N, M;
typedef long long ll;
int arr[1001][2];
ll dp[1001][11];
ll max[1001][1001];

ll solve(int idx, int k)
{
    if (k == 0 && idx == N)
        return 0;
    if (k == 0 || idx == N)
        return -1e18;
    if (dp[idx][k] != -1)
        return dp[idx][k];
    ll &ret = dp[idx][k];
    ret = 0;
    for (int i = 0; i + idx < N; i++)
        ret = std::max(ret, max[idx][idx + i] + solve(idx + i + 1, k - 1));
    return ret;
}

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N >> M;
    for (int i = 0; i < N; i++)
        std::cin >> arr[i][0] >> arr[i][1];
    for (int i = 0; i < N; i++)
    {
        int m = arr[i][0];
        ll sum = arr[i][1];
        max[i][i] = arr[i][1];
        for (int j = i + 1; j < N; j++)
        {
            if (m < arr[j][0])
            {
                m = arr[j][0];
                sum = arr[j][1];
            }
            else if (m == arr[j][0])
                sum += arr[j][1];
            max[i][j] = sum;
        }
    }
    memset(dp, -1, sizeof(dp));
    std::cout << solve(0, M) << '\n';
}
