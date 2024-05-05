#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

int N, M, ans;
int map[1010][1010];
int dp[1010][1010];
int startx, starty;

std::vector< std::pair<int ,int> > v;

int solve(int y, int x)
{
    if (y < 1 || x < startx || y > N || x > M)
        return 0;
    if (x == startx && map[y][x] == 'R')
        return 1;
    if (map[y][x] == '#')
        return 0;
    int &ret = dp[y][x];
    if (ret != -1)
        return ret;
    if (y == 1 && x == 1)
        return ret = 1;
    ret = 0;
    ret = std::max(ret, solve(y - 1, x - 1));
    ret = std::max(ret, solve(y, x - 1));
    ret = std::max(ret, solve(y + 1, x - 1));
    if (map[y][x] == 'C' && ret > 0)
        ret++;
    return ret;
}

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N >> M;
    for (int i = 1; i <= N; i++)
    {
        std::string s;
        std::cin >> s;
        for (int j = 1; j <= M; j++)
        {
            map[i][j] = s[j - 1];
            if (map[i][j] == 'O')
                v.push_back(std::make_pair(i, j));
            if (map[i][j] == 'R')
            {
                starty = i;
                startx = j;
            }
        }
    }
    memset(dp, -1, sizeof(dp));
    int ans = 0;
    for (int i = 0; i < v.size(); i++)
        ans = std::max(ans, solve(v[i].first, v[i].second));
    std::cout << ans - 1 << '\n';
}
