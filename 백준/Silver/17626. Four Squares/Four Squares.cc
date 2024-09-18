#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#include <map>

using namespace std;

typedef long long ll;
ll N;

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    cin >> N;
    vector<ll> dp(N + 1, 0);
    for (int i = 1; i * i < N; i++)
        dp[i * i] = 1;
    for (int i = 1; i <= N; i++)
    {
        if (dp[i] == 1)
            continue;
        dp[i] = 1e9;
        for (int j = 1; j * j <= i; j++)
            dp[i] = min(dp[i], dp[i - j * j] + 1);
    }
    cout << dp[N] << '\n';
}