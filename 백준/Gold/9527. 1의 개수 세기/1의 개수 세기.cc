#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#include <cmath>

using namespace std;

typedef long long ll;
ll A, B;
ll dp[55];

ll sol(ll x)
{
    ll ans = x & 1;
    for (int i = 54; i > 0; i--)
    {
        if (x & (1LL << i))
        {
            ans += dp[i - 1] + (x - (1LL << i) + 1);
            x -= (1LL << i);
        }
    }
    return ans;
}

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    cin >> A >> B;
    dp[0] = 1;
    for (int i = 1; i <= 54; i++)
        dp[i] = dp[i - 1] * 2 + (1LL << i);
    cout << sol(B) - sol(A - 1) << '\n';
}