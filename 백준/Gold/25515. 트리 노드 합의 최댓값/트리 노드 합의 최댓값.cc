#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#include <cmath>

int N;
typedef long long ll;
std::vector<int> v[100001];
ll dp[100001];
bool visited[100001];
int arr[100001];

ll solve(int idx)
{
    visited[idx] = true;
    ll &ret = dp[idx];
    if (ret != -1)
        return ret;
    ret = arr[idx];
    for (int i = 0; i < v[idx].size(); i++)
    {
        int next = v[idx][i];
        if (visited[next])
            continue;
        ret += solve(next);
    }
    if (ret < 0)
        ret = 0;
    return ret;
}

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N;
    for (int i = 0; i < N - 1; i++)
    {
        int a, b;
        std::cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for (int i = 0; i < N; i++)
        std::cin >> arr[i];
    memset(dp, -1, sizeof(dp));
    ll ans = solve(0);
    if (ans == 0)
        std::cout << arr[0] << '\n';
    else
        std::cout << ans << '\n';
}