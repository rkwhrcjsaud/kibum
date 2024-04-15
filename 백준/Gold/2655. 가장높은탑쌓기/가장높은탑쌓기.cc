#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

int N;

struct Block
{
    int index;
    int width;
    int height;
    int weight;
};

Block blocks[101];

int dp[101];
int parent[101];

int compare(const Block &a, const Block &b)
{
    return a.width > b.width;
}

int solve(int idx)
{
    int &ret = dp[idx];
    if (ret != -1)
        return ret;
    ret = blocks[idx].height;
    for (int i = idx + 1; i <= N; i++)
    {
        if (blocks[idx].weight > blocks[i].weight
            && ret < solve(i) + blocks[idx].height)
        {
            ret = std::max(ret, solve(i) + blocks[idx].height);
            parent[idx] = i;
        }
    }
    return ret;
}

void print(int idx, int cnt)
{
    if (idx == 0)
    {
        std::cout << cnt << '\n';
        return;
    }
    print(parent[idx], cnt + 1);
    std::cout << blocks[idx].index << '\n';
}

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N;
    for (int i = 1; i <= N; i++)
    {
        int a, b, c;
        std::cin >> a >> b >> c;
        blocks[i].height = b;
        blocks[i].width = a;
        blocks[i].weight = c;
        blocks[i].index = i;
    }
    std::sort(blocks + 1, blocks + N + 1, compare);
    blocks[0].weight = 1e9;
    std::fill(&dp[0], &dp[100], -1);
    solve(0);
    print(parent[0], 0);
}