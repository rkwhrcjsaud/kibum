#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <map>

int N;
std::vector<int> v[500001];
bool visited[500001];
int point[500001][3];
int dp[500001][3];
char colors[3] = {'R', 'G', 'B'};
char ans2[500001];

int solve(int idx, int cur)
{
    if (dp[idx][cur] != -1)
        return dp[idx][cur];
    int sum = 0;
    for (int i = 0; i < v[idx].size(); i++)
    {
        int res = 0;
        int next = v[idx][i];
        if (visited[next])
            continue;
        visited[next] = true;
        res = std::max(solve(next, (cur + 1) % 3), solve(next, (cur + 2) % 3));
        visited[next] = false;
        sum += res;
    }
    return dp[idx][cur] = sum + point[idx][cur];
}

void dfs(int idx, int cur)
{
    ans2[idx] = colors[cur];
    for (int i = 0; i < v[idx].size(); i++)
    {
        int next = v[idx][i];
        if (visited[next])
            continue;
        visited[next] = true;
        if (dp[next][(cur + 1) % 3] > dp[next][(cur + 2) % 3])
            dfs(next, (cur + 1) % 3);
        else
            dfs(next, (cur + 2) % 3);
        visited[next] = false;
    }
}

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N;
    for (int i = 1; i < N; i++)
    {
        int a, b;
        std::cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for (int i = 1; i <= N; i++)
        std::cin >> point[i][0] >> point[i][1] >> point[i][2];
    memset(dp, -1, sizeof(dp));
    visited[1] = true;
    int color = 0;
    int ans = 0;
    for (int i = 0; i < 3; i++)
    {
        if (ans < solve(1, i))
        {
            ans = solve(1, i);
            color = i;
        }
    }
    std::cout << ans << '\n';
    dfs(1, color);
    for (int i = 1; i <= N; i++)
        std::cout << ans2[i];
    std::cout << '\n';
}