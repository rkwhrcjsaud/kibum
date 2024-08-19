#include <string>
#include <vector>
#include <iostream>
using namespace std;
int N;
int dir[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

struct Puzzle {
    int size = 0; // 퍼즐의 크기
    int x1 = 50, y1 = 50; // 퍼즐의 최소 x, y
    int x2 = 0, y2 = 0; // 퍼즐의 최대 x, y
    vector<vector<int>> v; // 퍼즐이 담긴 배열
};

vector<Puzzle> tableP;
vector<Puzzle> boardP;
vector<vector<int>> copyTable;
vector<vector<int>> copyBoard;

void makeBoard(int y, int x, vector<vector<int>> &board, Puzzle &p)
{
    if (board[y][x] == 1)
        return ;
    board[y][x] = 1;
    p.size++;
    p.x1 = min(x, p.x1);
    p.x2 = max(x, p.x2);
    p.y1 = min(y, p.y1);
    p.y2 = max(y, p.y2);
    for (int i = 0; i < 4; i++)
    {
        int dy = y + dir[i][0];
        int dx = x + dir[i][1];
        if (dy < 0 || dy >= N || dx < 0 || dx >= N)
            continue ;
        if (board[dy][dx] == 1)
            continue ;
        makeBoard(dy, dx, board, p);
    }
}

void makePuzzle(int y, int x, vector<vector<int>> &table, Puzzle &p)
{
    if (table[y][x] == 0)
        return ;
    table[y][x] = 0;
    p.size++;
    p.x1 = min(x, p.x1);
    p.x2 = max(x, p.x2);
    p.y1 = min(y, p.y1);
    p.y2 = max(y, p.y2);
    for (int i = 0; i < 4; i++)
    {
        int dy = y + dir[i][0];
        int dx = x + dir[i][1];
        if (dy < 0 || dy >= N || dx < 0 || dx >= N)
            continue ;
        if (table[dy][dx] == 0)
            continue ;
        makePuzzle(dy, dx, table, p);
    }
}

void copyBoardP(Puzzle &p)
{
    int n = p.y2 - p.y1 + 1;
    int m = p.x2 - p.x1 + 1;
    p.v.resize(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            p.v[i][j] = copyBoard[p.y1 + i][p.x1 + j] ? 0 : 1;
        }
    }
}

void copyPuzzle(Puzzle &p)
{
    int n = p.y2 - p.y1 + 1;
    int m = p.x2 - p.x1 + 1;
    p.v.resize(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            p.v[i][j] = copyTable[p.y1 + i][p.x1 + j];
        }
    }
}

vector<vector<int>> rotate(vector<vector<int>> arr)
{
    vector<vector<int>> ret;
    int n = arr.size();
    int m = arr[0].size();
    ret.resize(m, vector<int>(n, 0));
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            ret[i][j] = arr[n - 1 - j][i];
    return ret;
}

bool isSame(Puzzle &a, Puzzle &b)
{
    if (a.size != b.size)
        return false;
    vector<vector<int>> tmp = b.v;
    for (int i = 0; i < 4; i++)
    {
        if (tmp == a.v)
            return true;
        tmp = rotate(tmp);
    }
    return false;
}

int solution(vector<vector<int>> game_board, vector<vector<int>> table) {
    int answer = 0;
    N = game_board.size();
    copyTable = table;
    copyBoard = game_board;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (table[i][j] == 0)
                continue ;
            Puzzle p;
            makePuzzle(i, j, table, p);
            copyPuzzle(p);
            tableP.push_back(p);
        }
    }
    
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (game_board[i][j] == 1)
                continue ;
            Puzzle p;
            makeBoard(i, j, game_board, p);
            copyBoardP(p);
            boardP.push_back(p);
        }
    }
    
    vector<bool> visitedB(boardP.size(), false);
    vector<bool> visitedP(tableP.size(), false);
    for (int i = 0; i < boardP.size(); i++)
    {
        for (int j = 0; j < tableP.size(); j++)
        {
            if (visitedB[i] || visitedP[j])
                continue ;
            if (isSame(boardP[i], tableP[j]))
            {
                visitedB[i] = true;
                visitedP[j] = true;
                answer += boardP[i].size;
            }
        }
    }
    
    return answer;
}