#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

int N;
typedef long long ll;
int arr[100001];
std::vector<ll> v;
ll sum[100001];
const int MOD = 1e9 + 7;

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N;
    for (int i = 0; i < N; i++)
    {
        int num;
        std::cin >> num;
        arr[num]++;
    }
    for (int i = 1; i <= 100000; i++)
    {
        if (arr[i] == 0)
            continue;
        v.push_back(arr[i] * i);
    }
    for (int i = 0; i < v.size(); i++)
    {
        sum[i] = v[i];
        if (i > 0)
            sum[i] += sum[i - 1];
    }
    ll ans = 0;
    for (int i = 1; i < v.size() - 1; i++)
    {
        ll left = sum[i - 1];
        ll right = sum[v.size() - 1] - sum[i];
        ans = (ans + ((left * v[i]) % MOD) * right % MOD) % MOD;
    }
    std::cout << ans << '\n';
}