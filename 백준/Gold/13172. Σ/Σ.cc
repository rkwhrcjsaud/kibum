#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

int M;
vector<vector<int> > v;
const int MOD = 1e9 + 7;

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int myPow(int a, int b)
{
    if (b == 0)
        return 1;
    if (b % 2)
        return (long long)a * myPow(a, b - 1) % MOD;
    int half = myPow(a, b / 2);
    return (long long)half * half % MOD;
}

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    cin >> M;
    v.resize(M, vector<int>(2, 0));
    long long ans = 0;
    for (int i = 0; i < M; i++)
    {
        cin >> v[i][0] >> v[i][1];
        int g = gcd(v[i][0], v[i][1]);
        v[i][0] /= g; // 분모
        v[i][1] /= g; // 분자
        int tmp = myPow(v[i][0], MOD - 2);
        ans += ((long long)v[i][1] * tmp) % MOD;
        ans %= MOD;
    }
    cout << ans % MOD << '\n';
}