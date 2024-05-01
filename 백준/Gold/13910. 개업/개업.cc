#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

int N, M;
int arr[101];
int dp[10001];
std::vector<int> v;

int solve(int x)
{
    if (x == N)
        return 0;
    int &ret = dp[x];
    if (ret != -1)
        return ret;
    ret = 1e9;
    for (int i = 0; i < v.size(); i++)
    {
        if (x + v[i] <= N)
            ret = std::min(ret, solve(x + v[i]) + 1);
    }
    return ret;
}

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N >> M;
    for (int i = 0; i < M; i++)
    {
        std::cin >> arr[i];
        v.push_back(arr[i]);
    }
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (i == j)
                continue;
            v.push_back(arr[i] + arr[j]);
        }
    }
    for (int i = 0; i < N; i++)
        dp[i] = -1;
    std::cout << (solve(0) == 1e9 ? -1 : solve(0)) << '\n';
}