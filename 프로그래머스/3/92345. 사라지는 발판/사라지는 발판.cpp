#include <string>
#include <vector>
#include <iostream>

using namespace std;

int N, M;
int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
int INF;

int sol(vector<vector<int>> board, vector<int> aloc, vector<int> bloc, int turn)
{
    vector<int> pos = turn % 2 ? bloc : aloc;
    if (board[pos[0]][pos[1]] == 0)
        return INF - turn;
    board[pos[0]][pos[1]] = 0;
    int ret = -INF;
    for (int i = 0; i < 4; i++)
    {
        vector<int> next = pos;
        next[0] += dir[i][0];
        next[1] += dir[i][1];
        if (next[0] < 0 || next[0] >= N)
            continue ;
        if (next[1] < 0 || next[1] >= M)
            continue ;
        if (board[next[0]][next[1]] == 0)
            continue ;
        if (turn % 2 == 0)
            ret = max(ret, sol(board, next, bloc, turn + 1));
        else
            ret = max(ret, sol(board, aloc, next, turn + 1));
    }
    if (ret == -INF)
        return INF - turn;
    return -ret;
}

int solution(vector<vector<int>> board, vector<int> aloc, vector<int> bloc) {
    int answer = -1;
    N = board.size();
    M = board[0].size();
    INF = N * M;
    answer = INF - abs(sol(board, aloc, bloc, 0));
    return answer;
}