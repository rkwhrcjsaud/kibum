#include <string>
#include <vector>
#include <string.h>
#include <iostream>
#include <queue>

using namespace std;

struct Pos {
    Pos(int y, int x, int w, int d) : y(y), x(x), w(w), d(d) {};
    int y, x, w, d;
};
int N;
int dp[26][26][4];
int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
const int INF = 1e9;
queue<Pos> q;

int solution(vector<vector<int>> board) {
    int answer = INF;
    N = board.size();
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            for (int k = 0; k < 4; k++)
                dp[i][j][k] = INF;
    for (int i = 0; i < 4; i++)
    {
        Pos pos(0, 0, 0, i);
        q.push(pos);
    }
    while (!q.empty())
    {
        int cy = q.front().y;
        int cx = q.front().x;
        int cw = q.front().w;
        int cd = q.front().d;
        q.pop();
        if (cy == N - 1 && cx == N - 1)
            continue ;
        for (int i = 0; i < 4; i++)
        {
            int ny = cy + dir[i][0];
            int nx = cx + dir[i][1];
            int nw = cw + 100 * ((cd == i) ? 1 : 6);
            int nd = i;
            if (ny < 0 || ny >= N || nx < 0 || nx >= N)
                continue ;
            if (board[ny][nx] == 1)
                continue ;
            if (abs(cd - nd) == 2)
                continue ;
            if (dp[ny][nx][nd] < nw)
                continue ;
            dp[ny][nx][nd] = nw;
            Pos tmp(ny, nx, nw, nd);
            q.push(tmp);
        }
    }
    for (int i = 0; i < 4; i++)
        answer = min(answer, dp[N - 1][N - 1][i]);
    return answer;
}