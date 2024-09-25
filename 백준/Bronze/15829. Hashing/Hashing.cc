#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

int N;
string s;
long long r[51];
const int MOD = 1234567891;

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    cin >> N >> s;
    r[0] = 1;
    for (int i = 1; i <= N; i++)
        r[i] = (r[i - 1] * 31) % MOD;
    long long sum = 0;
    for (int i = 0; i < N; i++)
        sum = (sum + (s[i] - 'a' + 1) * r[i]) % MOD;
    cout << sum << '\n';
}