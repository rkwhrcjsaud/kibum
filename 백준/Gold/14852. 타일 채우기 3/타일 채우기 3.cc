#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <map>
#include <set>

using namespace std;

int N;
int dp[1000001][2];
const int MOD = 1e9 + 7;
typedef long long ll;

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    cin >> N;
    dp[1][0] = 2;
    dp[0][0] = dp[1][1] = 1;
    for (int i = 2; i <= N; i++)
    {
        dp[i][0] = ((ll)dp[i - 1][0] * 2 + dp[i - 1][1] * 2 + dp[i - 2][0]) % MOD;
        dp[i][1] = (dp[i - 1][0] + dp[i - 1][1]) % MOD;
    }
    cout << dp[N][0] << '\n';
}