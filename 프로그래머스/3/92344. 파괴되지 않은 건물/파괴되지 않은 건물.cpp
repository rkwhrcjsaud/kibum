#include <string>
#include <vector>
#include <iostream>

using namespace std;
int R, C;

void sol(vector<vector<int>> &board, vector<int> skill)
{
    int degree = skill[5];
    if (skill[0] == 1)
        degree *= -1;
    int r1 = skill[1];
    int c1 = skill[2];
    int r2 = skill[3];
    int c2 = skill[4];
    board[r1][c1] += degree;
    if (c2 + 1 < C) board[r1][c2 + 1] -= degree; 
    if (r2 + 1 < R) board[r2 + 1][c1] -= degree;
    if (c2 + 1 < C && r2 + 1 < R) board[r2 + 1][c2 + 1] += degree;
}

int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    int answer = 0;
    R = board.size();
    C = board[0].size();
    vector<vector<int>> tmp(R, vector<int>(C, 0));
    for (int i = 0; i < skill.size(); i++)
    {
        sol(tmp, skill[i]);
    }
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            if (i == 0 && j == 0)
                continue ;
            if (i == 0)
                tmp[i][j] += tmp[i][j - 1];
            if (j == 0)
                tmp[i][j] += tmp[i - 1][j];
            if (i != 0 && j != 0)
                tmp[i][j] += tmp[i - 1][j] + tmp[i][j - 1] - tmp[i - 1][j - 1];
        }
    }
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            if (tmp[i][j] + board[i][j] > 0)
                answer++;
        }
    }
    return answer;
}