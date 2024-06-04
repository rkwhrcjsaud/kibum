#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

class Node
{
    public:
    int next, flag, idx;
    Node(int next, int flag, int idx) : next(next), flag(flag), idx(idx) {};
};

int N;
std::vector< Node > tree[100001];
std::vector< bool > flip(100001, 0);
std::vector< bool > ans(100001, 0);
int dp[100001];
int min = 1e9;


int dfs(int idx, int prev)
{
    int ret = 0;
    for (int i = 0; i < tree[idx].size(); i++)
    {
        int next = tree[idx][i].next;
        if (next == prev)
            continue ;
        flip[tree[idx][i].idx] = tree[idx][i].flag;
        ret += dfs(next, idx) + tree[idx][i].flag;
    }
    return ret;
}

void solve(int idx, int prev, int num)
{
    if (min > num)
    {
        min = num;
        for (int i = 0; i < N - 1; i++)
            ans[i] = flip[i];
    }
    for (int i = 0; i < tree[idx].size(); i++)
    {
        int next = tree[idx][i].next;
        int flag = tree[idx][i].flag;
        if (next == prev)
            continue ;
        if (flag)
        {
            flip[tree[idx][i].idx] = 0;
            solve(next, idx, num - 1);
            flip[tree[idx][i].idx] = 1;
        }
        else
        {
            flip[tree[idx][i].idx] = 1;
            solve(next, idx, num + 1);
            flip[tree[idx][i].idx] = 0;
        }
    }
}

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N;
    for (int i = 0; i < N - 1; i++)
    {
        int a, b;
        std::cin >> a >> b;
        tree[a].push_back(Node(b, 0, i));
        tree[b].push_back(Node(a, 1, i));
    }
    int t = dfs(1, 0);
    solve(1, 0, t);
    for (int i = 0; i < N - 1; i++)
        std::cout << ans[i];
    std::cout << '\n';
}