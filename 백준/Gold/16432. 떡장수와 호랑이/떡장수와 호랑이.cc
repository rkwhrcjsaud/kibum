#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <climits>

int N;
bool arr[1001][10];
int dp[1001][10];
std::vector<int> ans;

int dfs(int level, int prev)
{
    if (level == N)
    {
        for (int i = 0; i < ans.size(); i++)
            std::cout << ans[i] << '\n';
        exit(0);
    }
    int &ret = dp[level][prev];
    if (ret != -1)
        return ret;
    ret = 0;
    for (int i = 0; i < 10; i++)
    {
        if (arr[level][i] && i != prev)
        {
            ans.push_back(i);
            ret = dfs(level + 1, i);
            ans.pop_back();
            if (ret)
                return ret;
        }
    }
    return ret;
}

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N;
    for (int i = 0; i < N; i++)
    {
        int tmp;
        std::cin >> tmp;
        for (int j = 0; j < tmp; j++)
        {
            int tmp2;
            std::cin >> tmp2;
            arr[i][tmp2] = true;
        }
    }
    std::fill(&dp[0][0], &dp[N][10], -1);
    dfs(0, 0);
    std::cout << -1 << '\n';
}