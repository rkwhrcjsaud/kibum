#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#include <cmath>

using namespace std;

int T;
int N, M;
int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int ans = 0;

bool check(int y, int x, vector<string> &board, int &bit, vector<vector<bool> > &visited)
{
    if (visited[y][x])
        return false;
    if (board[y][x] == '.')
        return true;
    if (board[y][x] >= 'A' && board[y][x] <= 'Z')
    {
        if (bit & (1 << (board[y][x] - 'A')))
        {
            board[y][x] = '.';
            return true;
        }
        return false;
    }
    if (board[y][x] >= 'a' && board[y][x] <= 'z')
    {
        bit |= 1 << (board[y][x] - 'a');
        board[y][x] = '.';
        return true;
    }
    if (board[y][x] == '$')
    {
        ans++;
        board[y][x] = '.';
        return true;
    }
    return false;
}

bool bfs(int y, int x, vector<string> &board, int &bit, vector<vector<bool> > &visited)
{
    queue<pair<int, int> > q;
    q.push(make_pair(y, x));
    bool flag = false;
    while (!q.empty())
    {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int ny = y + dir[i][0];
            int nx = x + dir[i][1];
            if (ny < 0 || ny >= N || nx < 0 || nx >= M || visited[ny][nx] || board[ny][nx] == '*')
                continue;
            char tmp = board[ny][nx];
            if (!check(ny, nx, board, bit, visited))
                continue;
            visited[ny][nx] = true;
            if (tmp != board[ny][nx])
                flag = true;
            q.push(make_pair(ny, nx));
        }
    }
    return flag;
}

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    cin >> T;
    while (T--)
    {
        cin >> N >> M;
        ans = 0;
        vector<string> board(N);
        for (int i = 0; i < N; i++)
            cin >> board[i];
        int bit = 0;
        string s;
        cin >> s;
        if (s != "0")
        {
            for (int i = 0; i < s.size(); i++)
                bit |= 1 << (s[i] - 'a');
        }
        bool flag = true;
        while (flag)
        {
            vector<vector<bool> > visited(N, vector<bool>(M, false));
            flag = false;
            for (int i = 0; i < N; i++)
            {
                if (i == 0 || i == N - 1)
                {
                    for (int j = 0; j < M; j++)
                    {
                        if (check(i, j, board, bit, visited))
                            if (bfs(i, j, board, bit, visited))
                                flag = true;
                    }
                }
                else
                {
                    if (check(i, 0, board, bit, visited))
                        if (bfs(i, 0, board, bit, visited))
                            flag = true;
                    if (check(i, M - 1, board, bit, visited))
                        if (bfs(i, M - 1, board, bit, visited))
                            flag = true;
                }
            }
        }
        cout << ans << '\n';
    }
}