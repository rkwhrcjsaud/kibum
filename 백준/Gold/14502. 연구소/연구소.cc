#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

int N, M;
vector<vector<int> > board;
vector<pair<int, int> > virus;
int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int bfs()
{
    queue<pair<int, int> > q;
    vector<vector<bool> > visited(N, vector<bool>(M, false));
    for (int i = 0; i < virus.size(); i++)
    {
        q.push(virus[i]);
        visited[virus[i].first][virus[i].second] = true;
    }
    int ret = 0;
    while (!q.empty())
    {
        int hereY = q.front().first;
        int hereX = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int thereY = hereY + dir[i][0];
            int thereX = hereX + dir[i][1];
            if (thereY < 0 || thereY >= N || thereX < 0 || thereX >= M)
                continue;
            if (board[thereY][thereX] == 0 && !visited[thereY][thereX])
            {
                q.push(make_pair(thereY, thereX));
                visited[thereY][thereX] = true;
            }
        }
    }
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            if (board[i][j] == 0 && !visited[i][j])
                ret++;
    return ret;
}

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    cin >> N >> M;
    board.resize(N, vector<int>(M, 0));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> board[i][j];
            if (board[i][j] == 2)
                virus.push_back(make_pair(i, j));
        }
    }
    int ans = 0;
    for (int i = 0; i < N * M; i++)
    {
        int y1 = i / M, x1 = i % M;
        if (board[y1][x1] != 0)
            continue;
        board[y1][x1] = 1;
        for (int j = i + 1; j < N * M; j++)
        {
            int y2 = j / M, x2 = j % M;
            if (board[y2][x2] != 0)
                continue;
            board[y2][x2] = 1;
            for (int k = j + 1; k < N * M; k++)
            {
                int y3 = k / M, x3 = k % M;
                if (board[y3][x3] != 0)
                    continue;
                board[y3][x3] = 1;
                ans = max(ans, bfs());
                board[y3][x3] = 0;
            }
            board[y2][x2] = 0;
        }
        board[y1][x1] = 0;
    }
    cout << ans << '\n';
}