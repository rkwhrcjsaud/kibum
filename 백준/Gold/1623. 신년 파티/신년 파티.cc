#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

int N;
int point[200001];
std::vector<int> adj[200001];
int dp[200001][2];
std::vector<int> path;

int solve(int idx, int flag)
{
    if (dp[idx][flag] != -1)
        return dp[idx][flag];
    if (adj[idx].empty())
        return dp[idx][flag] = point[idx] * flag;
    if (flag)
    {
        int sum = 0;
        for (int i = 0; i < adj[idx].size(); i++)
            sum += solve(adj[idx][i], 0);
        return dp[idx][flag] = sum + point[idx];
    }
    else
    {
        int sum = 0;
        for (int i = 0; i < adj[idx].size(); i++)
            sum += std::max(solve(adj[idx][i], 0), solve(adj[idx][i], 1));
        return dp[idx][flag] = sum;
    }
}

void savePath(int idx, int flag)
{
    if (adj[idx].empty())
    {
        if (flag)
            path.push_back(idx);
        return;
    }
    if (flag)
    {
        path.push_back(idx);
        for (int i = 0; i < adj[idx].size(); i++)
            savePath(adj[idx][i], 0);
    }
    else
    {
        for (int i = 0; i < adj[idx].size(); i++)
        {
            if (dp[adj[idx][i]][0] < dp[adj[idx][i]][1])
                savePath(adj[idx][i], 1);
            else
                savePath(adj[idx][i], 0);
        }
    }
}



int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N;
    for (int i = 1; i <= N; i++)
        std::cin >> point[i];
    for (int i = 2; i <= N; i++)
    {
        int a;
        std::cin >> a;
        adj[a].push_back(i);
    }
    memset(dp, -1, sizeof(dp));
    std::cout << solve(1, 1) << ' ' << solve(1, 0) << '\n';
    savePath(1, 1);
    std::sort(path.begin(), path.end());
    for (int i = 0; i < path.size(); i++)
        std::cout << path[i] << ' ';
    std::cout << "-1\n";
    path.clear();
    savePath(1, 0);
    std::sort(path.begin(), path.end());
    for (int i = 0; i < path.size(); i++)
        std::cout << path[i] << ' ';
    std::cout << "-1\n";
}