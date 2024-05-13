#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

typedef long long ll;
ll N, M, K, S, T;
std::vector<std::pair<ll, ll> > adj[100001];
ll dp[100001][11]; // dp[i][j] = i번째 도시에 위치해있고 남아있는 리프트횟수가 j번일 때 T도시에서 끝나는 최대 시간

ll solve(int idx, int k)
{
    if (k < 0)
        return -1e18;
    if (idx == T && k == 0)
        return 0;
    ll &ret = dp[idx][k];
    if (ret != -1)
        return ret;
    ret = -1e18;
    for (int i = 0; i < adj[idx].size(); i++)
    {
        ll next = adj[idx][i].first;
        ll time = adj[idx][i].second;
        if (time == 0)
        {
            ret = std::max(ret, solve(next, k - 1));
            continue;
        }
        ret = std::max(ret, solve(next, k) + time);
    }
    return dp[idx][k];
}

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N >> M >> K >> S >> T;
    for (int i = 0; i < M; i++)
    {
        int a, b, t;
        std::cin >> a >> b >> t;
        adj[a].push_back(std::make_pair(b, t));
        adj[b].push_back(std::make_pair(a, 0));
    }
    memset(dp, -1, sizeof(dp));
    ll ans = solve(S, K);
    if (ans < 0)
        std::cout << -1 << '\n';
    else
        std::cout << ans << '\n';
}
