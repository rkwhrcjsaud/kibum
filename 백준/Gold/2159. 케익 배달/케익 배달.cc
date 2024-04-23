#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <climits>

typedef long long ll;
int N, startX, startY;
const ll MAX = 1e14L;
std::vector<std::pair<ll, ll> > v;
ll dp[100001][5];
ll dydx[5][2] = {{0, 0}, {0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N >> startX >> startY;
    for (ll i = 0; i < N; i++)
    {
        ll x, y;
        std::cin >> x >> y;
        v.push_back(std::make_pair(x, y));
    }
    std::fill(&dp[0][0], &dp[100000][5], MAX);
    for (ll i = 0; i <= 4; i++)
    {
        ll nx = v[0].first + dydx[i][0];
        ll ny = v[0].second + dydx[i][1];
        if (nx < 0 || ny < 0 || nx > 100000 || ny > 100000)
            continue;
        dp[0][i] = std::min(dp[0][i], std::abs(nx - startX) + std::abs(ny - startY));
    }
    for (ll i = 1; i < N; i++)
    {
        ll x = v[i].first;
        ll y = v[i].second;
        for (int j = 0; j <= 4; j++)
        {
            ll curX = x + dydx[j][0];
            ll curY = y + dydx[j][1];
            if (curX < 0 || curY < 0 || curX > 100000 || curY > 100000)
                continue;
            for (int k = 0; k <= 4; k++)
            {
                ll prevX = v[i - 1].first + dydx[k][0];
                ll prevY = v[i - 1].second + dydx[k][1];
                if (prevX < 0 || prevY < 0 || prevX > 100000 || prevY > 100000)
                    continue;
                dp[i][j] = std::min(dp[i][j], dp[i - 1][k] + std::abs(curX - prevX) + std::abs(curY - prevY));
            }
        }
    }
    ll result = MAX;
    for (ll i = 0; i <= 4; i++)
    {
        result = std::min(result, dp[N - 1][i]);
    }
    std::cout << result << '\n';
}