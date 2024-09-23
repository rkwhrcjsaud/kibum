#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

int R, C, T;
vector<vector<int> > board;
int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    cin >> R >> C >> T;
    board.resize(R, vector<int>(C, 0));
    int cleaner = -1;
    int total = 0;
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            cin >> board[i][j];
            if (board[i][j] == -1)
                cleaner = i;
            else if (board[i][j] != 0)
                total += board[i][j];
        }
    }
    while (T--)
    {
        vector<vector<int> > tmp(R, vector<int>(C, 0));
        for (int i = 0; i < R; i++)
        {
            for (int j = 0; j < C; j++)
            {
                if (board[i][j] == 0 || board[i][j] == -1)
                    continue;
                int cnt = 0;
                for (int k = 0; k < 4; k++)
                {
                    int thereY = i + dir[k][0];
                    int thereX = j + dir[k][1];
                    if (thereY < 0 || thereY >= R || thereX < 0 || thereX >= C || board[thereY][thereX] == -1)
                        continue;
                    tmp[thereY][thereX] += board[i][j] / 5;
                    cnt++;
                }
                tmp[i][j] += board[i][j] - (board[i][j] / 5) * cnt;
            }
        }
        if (cleaner != 1)
        {
            for (int i = cleaner - 1; i > 0; i--)
                tmp[i][0] = tmp[i - 1][0];
            for (int i = 0; i < C - 1; i++)
                tmp[0][i] = tmp[0][i + 1];
            for (int i = 0; i < cleaner - 1; i++)
                tmp[i][C - 1] = tmp[i + 1][C - 1];
            for (int i = C - 1; i > 1; i--)
                tmp[cleaner - 1][i] = tmp[cleaner - 1][i - 1];
            tmp[cleaner - 1][1] = 0;
        }
        if (cleaner != R - 1)
        {
            for (int i = cleaner; i < R - 1; i++)
                tmp[i][0] = tmp[i + 1][0];
            for (int i = 0; i < C - 1; i++)
                tmp[R - 1][i] = tmp[R - 1][i + 1];
            for (int i = R - 1; i > cleaner; i--)
                tmp[i][C - 1] = tmp[i - 1][C - 1];
            for (int i = C - 1; i > 1; i--)
                tmp[cleaner][i] = tmp[cleaner][i - 1];
            tmp[cleaner][1] = 0;
        }
        board = tmp;
        total -= board[cleaner - 1][0];
        total -= board[cleaner][0];
        board[cleaner - 1][0] = -1;
        board[cleaner][0] = -1;
    }
    cout << total << '\n';
}
