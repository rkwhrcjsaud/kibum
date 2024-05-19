#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <sstream>
#include <map>

typedef long long ll;
int N, M;
std::vector<int> v;
ll dp[1010][1010];

ll solve(int l, int r)
{
    if (l == r)
        return 0;
    ll &ret = dp[l][r];
    if (ret != -1)
        return ret;
    ret = 1e9;
    for (int i = l; i < r; i++)
        ret = std::min(ret, solve(l, i) + solve(i + 1, r) + v[r + 1] - v[l]);
    return ret;
}

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N >> M;
    v.push_back(0);
    for (int i = 0; i < M; i++)
    {
        int num;
        std::cin >> num;
        v.push_back(num);
    }
    v.push_back(N);
    std::sort(v.begin(), v.end());
    memset(dp, -1, sizeof(dp));
    std::cout << solve(0, M) << '\n';
}