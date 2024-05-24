#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

int N;
typedef long long ll;
std::vector<std::pair<ll, ll> > v;
int left[301];
int right[301];
int dp[301];

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N;
    for (int i = 0; i < N; i++)
    {
        int a, b;
        std::cin >> a >> b;
        v.push_back(std::make_pair(a, b));
        left[i] = i;
        right[i] = i;
    }
    std::sort(v.begin(), v.end());
    for (int i = 0; i < N; i++)
    {
        ll l = v[i].first - v[i].second;
        ll r = v[i].first + v[i].second;
        for (int j = i; j >= 0; j--)
        {
            if (v[j].first >= l)
            {
                l = std::min(l, v[j].first - v[j].second);
                left[i] = std::min(left[i], j);
            }
        }
        for (int j = i + 1; j < N; j++)
        {
            if (v[j].first <= r)
            {
                r = std::max(r, v[j].first + v[j].second);
                right[i] = std::max(right[i], j);
            }
        }
    }
    for (int i = 0; i < N; i++)
        dp[i] = 1e9;
    dp[0] = 1;
    for (int i = 0; i < N; i++)
    {
        if (left[i] - 1 < 0)
            dp[i] = std::min(dp[i], 1);
        else
            dp[i] = std::min(dp[i], dp[left[i] - 1] + 1);
        for (int j = 0; j < i; j++)
        {
            if (right[j] >= i)
            {
                if (j == 0)
                    dp[i] = std::min(dp[i], 1);
                else
                    dp[i] = std::min(dp[i], dp[j - 1] + 1);
            }
        }
    }
    std::cout << dp[N - 1] << '\n';
}