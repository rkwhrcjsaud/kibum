#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

int N, M, K;
std::vector<std::pair<int, int> > v[501];
int arr[1001];
int dp[1001][501];

int solve(int idx, int town)
{
    if (idx == N)
        return 0;
    int &ret = dp[idx][town];
    if (ret != -1)
        return ret;
    ret = 0;
    for (int i = 0; i < v[town].size(); i++)
    {
        int next = v[town][i].first;
        int color = v[town][i].second;
        ret = std::max(ret, solve(idx + 1, next) + (arr[idx] == color ? 10 : 0));
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
        char c;
        std::cin >> c;
        if (c == 'G')
            arr[i] = 1;
        else if (c == 'B')
            arr[i] = 2;
    }
    std::cin >> M >> K;
    for (int i = 0; i < K; i++)
    {
        int a, b, num = 0;
        char c;
        std::cin >> a >> b >> c;
        if (c == 'G')
            num = 1;
        else if (c == 'B')
            num = 2;
        v[a].push_back(std::make_pair(b, num));
        v[b].push_back(std::make_pair(a, num));
    }
    memset(dp, -1, sizeof(dp));
    std::cout << solve(0, 1) << '\n';
}