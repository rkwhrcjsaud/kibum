#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

int N, M, K;
int candy[30001];
int parent[30001];
int child[30001];
std::vector< std::pair<int, int> > v;
int dp[30001][3001];

int find(int x)
{
    if (parent[x] == x)
        return x;
    return parent[x] = find(parent[x]);
}

void merge(int x, int y)
{
    x = find(x);
    y = find(y);
    if (x == y)
        return ;
    parent[y] = x;
    candy[x] += candy[y];
    child[x] += child[y];
    candy[y] = 0;
    return ;
}

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N >> M >> K;
    std::fill(child, child + 30001, 1);
    std::fill(&dp[0][0], &dp[30000][3000], -1);
    for (int i = 1; i <= N; ++i)
        parent[i] = i;
    for (int i = 1; i <= N; ++i)
        std::cin >> candy[i];
    for (int i = 0; i < M; i++)
    {
        int a, b;
        std::cin >> a >> b;
        merge(a, b);
    }
    v.push_back(std::make_pair(0, 0));
    for (int i = 1; i <= N; i++)
    {
        if (parent[i] == i)
            v.push_back(std::make_pair(candy[i], child[i]));
    }
    int ans = 0;
    dp[0][0] = 0;
    for (int i = 1; i < v.size(); i++)
    {
        for (int j = 0; j < K; j++)
        {
            dp[i][j] = dp[i - 1][j];
            if (j >= v[i].second)
                dp[i][j] = std::max(dp[i][j], dp[i - 1][j - v[i].second] + v[i].first);
            ans = std::max(ans, dp[i][j]);
        }
    }
    std::cout << ans << '\n';
}