#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#include <cmath>

int R, C;
const int MOD = 1e9 + 9;
int d[8][2] = {{-1, -2}, {-2, -1}, {-2, 1}, {-1, 2}, {1, -2}, {2, -1}, {2, 1}, {1, 2}};
int dp[401][401];
int step[401][401];
typedef std::pair<int, int> pii;

pii bfs(void)
{
    int cnt = 0;
    std::queue<pii> q;
    q.push(std::make_pair(1, 1));
    dp[1][1] = 1;
    step[1][1] = 0;
    while (!q.empty())
    {
        pii cur = q.front();
        q.pop();
        if (cur.first == R && cur.second == C)
            return std::make_pair(step[cur.first][cur.second], dp[cur.first][cur.second]);
        for (int i = 0; i < 8; i++)
        {
            int nx = cur.first + d[i][0];
            int ny = cur.second + d[i][1];
            if (nx < 1 || nx > R || ny < 1 || ny > C)
                continue ;
            if (step[nx][ny] != -1 && step[nx][ny] < step[cur.first][cur.second] + 1)
                continue ;
            step[nx][ny] = step[cur.first][cur.second] + 1;
            if (dp[nx][ny] != 0)
                dp[nx][ny] = (dp[nx][ny] + dp[cur.first][cur.second]) % MOD;
            else
            {
                dp[nx][ny] = dp[cur.first][cur.second];
                q.push(std::make_pair(nx, ny));
            }
        }
    }
    return std::make_pair(-1, -1);
}

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> R >> C;
    memset(step, -1, sizeof(step));
    pii ans = bfs();
    if (ans.first < 0)
        std::cout << "None\n";
    else
        std::cout << ans.first << ' ' << ans.second << '\n';
}