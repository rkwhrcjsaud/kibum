#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;


const int INF = 1e9;

struct Pos {
    int y1, x1, y2, x2;
    int w;
    Pos(int y1, int x1, int y2, int x2, int w) : y1(y1), x1(x1), y2(y2), x2(x2), w(w) {};
};

struct Compare {
    bool operator()(const Pos& a, const Pos& b) {
        return a.w > b.w;
    }
};

priority_queue<Pos, vector<Pos>, Compare> q;

int dp[102][102][2]; // y,x 가 드론이 가로일 경우에는 드론의 오른쪽, 세로일 경우에는 드론의 아래쪽이다.
// k = 0 : 드론이 가로, k = 1 : 드론이 세로

int rowToCol[4][4] = {{0, 1, 1, 0}, {0, 0, 1, -1}, {-1, 0, 0, -1}, {-1, 1, 0, 0}};
int colToRow[4][4] = {{1, 0, 0, 1}, {0, 0, -1, 1}, {0, -1, -1, 0}, {1, -1, 0, 0}};
int dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

int solution(vector<vector<int>> board) {
    int answer = 0;
    int N = board.size();
    for (int i = 0; i <= N; i++)
        for (int j = 0; j <= N; j++)
            for (int k = 0; k < 2; k++)
                dp[i][j][k] = INF;
    Pos p(0, 0, 0, 1, 0);
    q.push(p);
    while (!q.empty())
    {
        int cy1 = q.top().y1;
        int cx1 = q.top().x1;
        int cy2 = q.top().y2;
        int cx2 = q.top().x2;
        int cw = q.top().w;
        int cf = (cx1 == cx2) ? 1 : 0;
        q.pop();
        if (cy2 == N - 1 && cx2 == N - 1)
            break ;
        for (int i = 0; i < 4; i++)
        {
            int ny1 = cy1 + (cf ? colToRow[i][0] : rowToCol[i][0]);
            int nx1 = cx1 + (cf ? colToRow[i][1] : rowToCol[i][1]);
            int ny2 = cy2 + (cf ? colToRow[i][2] : rowToCol[i][2]);
            int nx2 = cx2 + (cf ? colToRow[i][3] : rowToCol[i][3]);
            int nw = cw + 1;
            int nf = cf ? 0 : 1;
            if (ny1 < 0 || ny1 >= N || nx1 < 0 || nx1 >= N)
                continue ;
            if (ny2 < 0 || ny2 >= N || nx2 < 0 || nx2 >= N)
                continue ;
            bool wall = 0;
            for (int i = min(cy1, ny1); i <= max(cy2, ny2); i++)
                for (int j = min(cx1, nx1); j <= max(cx2, nx2); j++)
                    if (board[i][j])
                        wall = 1;
            if (wall)
                continue ;
            if (dp[ny2][nx2][nf] != INF)
                continue ;
            dp[ny2][nx2][nf] = nw;
            q.push(Pos(ny1, nx1, ny2, nx2, nw));
        }
        for (int i = 0; i < 4; i++)
        {
            int ny1 = cy1 + dir[i][0];
            int nx1 = cx1 + dir[i][1];
            int ny2 = cy2 + dir[i][0];
            int nx2 = cx2 + dir[i][1];
            int nw = cw + 1;
            int nf = cf;
            if (ny1 < 0 || ny1 >= N || nx1 < 0 || nx1 >= N)
                continue ;
            if (ny2 < 0 || ny2 >= N || nx2 < 0 || nx2 >= N)
                continue ;
            if (board[ny1][nx1] || board[ny2][nx2])
                continue ;
            if (dp[ny2][nx2][nf] != INF)
                continue ;
            dp[ny2][nx2][nf] = nw;
            q.push(Pos(ny1, nx1, ny2, nx2, nw));
        }
    }
    answer = min(dp[N - 1][N - 1][0], dp[N - 1][N - 1][1]);
    return answer;
}