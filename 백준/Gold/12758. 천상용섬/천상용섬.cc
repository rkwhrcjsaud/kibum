#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <sstream>
#include <map>

int T, N;
std::vector< std::vector <int> > v;
std::vector< int > a;
int dp[301][301];
const int MOD = 1e9 + 7;

int solve(int idx, int prev)
{
    if (idx == N)
        return 1;
    int &ret = dp[idx][prev];
    if (ret != -1)
        return ret;
    ret = 0;
    std::vector<int>::iterator it = std::lower_bound(v[idx + 1].begin(), v[idx + 1].end(), v[idx][prev]);
    for (; it != v[idx + 1].end(); it++)
    {
        ret += solve(idx + 1, it - v[idx + 1].begin());
        ret %= MOD;
    }
    return ret;
}

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> T;
    while (T--)
    {
        std::cin >> N;
        v.clear();
        v.resize(N + 1);
        v[0].push_back(0);
        for (int i = 1; i <= N; i++)
        {
            int n;
            std::cin >> n;
            std::vector<int> tmp;
            for (int j = 1; j * j <= n; j++)
            {
                if (n % j == 0)
                {
                    tmp.push_back(j);
                    if (j * j != n)
                        tmp.push_back(n / j);
                }
            }
            std::sort(tmp.begin(), tmp.end());
            v[i] = tmp;
        }
        memset(dp, -1, sizeof(dp));
        std::cout << solve(0, 0) << '\n';
    }
}