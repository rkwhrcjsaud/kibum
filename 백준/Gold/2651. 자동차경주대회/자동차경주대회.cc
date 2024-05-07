#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

int D, N;
int dist[110];
int arr[110];
long long dp[110][110];
std::vector<int> ans;

long long solve(int idx, int prev)
{
    if (idx == N + 1)
        return 0;
    long long &ret = dp[idx][prev];
    if (ret != -1)
        return ret;
    ret = 1e10;
    for (int i = idx + 1; i <= N + 1; i++)
    {
        if (dist[i] - dist[idx] > D)
            break ;
        ret = std::min(ret, solve(i, idx) + arr[i]);
    }
    return ret;
}

void print(int idx, int prev)
{
    if (idx == N + 1)
        return ;
    for (int i = idx + 1; i <= N + 1; i++)
    {
        if (dist[i] - dist[idx] > D)
            break ;
        if (dp[idx][prev] == dp[i][idx] + arr[i])
        {
            ans.push_back(i);
            print(i, idx);
            return ;
        }
    }
}

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> D >> N;
    for (int i = 1; i <= N + 1; i++)
    {
        std::cin >> dist[i];
        dist[i] += dist[i - 1];
    }
    for (int i = 1; i <= N; i++)
        std::cin >> arr[i];
    arr[N + 1] = 0;
    memset(dp, -1, sizeof(dp));
    std::cout << solve(0, 0) << '\n';
    print(0, 0);
    std::cout << ans.size() << '\n';
    for (int i = 0; i < ans.size(); i++)
        std::cout << ans[i] << ' ';
    std::cout << '\n';
}