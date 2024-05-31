#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

int N;
const int MOD = 1e9 + 7;
int num[100001];
std::vector<int> v[100001];
int dp[100001][10];
bool visited[100001];

int solve(int idx, int prev)
{
    int &ret = dp[idx][prev];
    if (ret != -1)
        return ret;
    ret = num[idx] >= prev ? 1 : 0;
    for (int i = 0; i < v[idx].size(); i++)
    {
        int next = v[idx][i];
        if (visited[next])
            continue;
        visited[next] = true;
        if (num[idx] >= prev)
            ret = (ret + solve(next, num[idx])) % MOD;
        ret = (ret + solve(next, prev)) % MOD;
        visited[next] = false;
    }
    return ret;
}

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N;
    for (int i = 1; i <= N; i++)
        std::cin >> num[i];
    for (int i = 0; i < N - 1; i++)
    {
        int a, b;
        std::cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    memset(dp, -1, sizeof(dp));
    visited[1] = true;
    std::cout << solve(1, 0) << '\n';
}