#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

int N, M, A, B;
int map[101][101];
int dp[101][101];
std::vector< std::pair<int, int> > v;

int solve(int x, int y, int x2, int y2)
{
    if (x == x2 && y == y2)
        return 1;
    int &ret = dp[x][y];
    if (ret != -1)
        return ret;
    ret = 0;
    if (x + 1 <= x2 && map[x + 1][y] != -1)
        ret += solve(x + 1, y, x2, y2);
    if (y + 1 <= y2 && map[x][y + 1] != -1)
        ret += solve(x, y + 1, x2, y2);
    return ret;
}

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N >> M >> A >> B;
    for (int i = 0; i < A + B; i++)
    {
        int a, b;
        std::cin >> a >> b;
        map[a][b] = (i >= A) ? -1 : 1;
    }
    memset(dp, -1, sizeof(dp));
    for (int i = 1; i <= M; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            if (map[j][i] == 1)
            {
                v.push_back(std::make_pair(j, i));
                break ;
            }
        }
        for (int j = N; j >= 1; j--)
        {
            if (map[j][i] == 1)
            {
                v.push_back(std::make_pair(j, i));
                break ;
            }
        }
    }
    v.push_back(std::make_pair(N, M));
    int ans = solve(1, 1, v[0].first, v[0].second);
    for (int i = 1; i < v.size(); i++)
        ans *= solve(v[i - 1].first, v[i - 1].second, v[i].first, v[i].second);
    std::cout << ans << '\n';
}