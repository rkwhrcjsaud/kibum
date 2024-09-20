#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

int N;

void sol(int y1, int x1, int y2, int x2, int n, vector<vector<char> > &board)
{
    if (n == 3)
    {
        board[y1][x1 + 2] = '*';
        board[y1 + 1][x1 + 1] = '*';
        board[y1 + 1][x1 + 3] = '*';
        for (int i = 0; i < 5; i++)
            board[y1 + 2][x1 + i] = '*';
        return;
    }
    sol(y1, x1 + n / 2, y1 + n / 2, x1 + n, n / 2, board);
    sol(y1 + n / 2, x1, y1 + n, x1 + n, n / 2, board);
    sol(y1 + n / 2, x1 + n, y1 + n, x1 + n * 2, n / 2, board);
}

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    cin >> N;
    vector<vector<char> > board(N, vector<char>(2 * N - 1, ' '));
    sol(0, 0, N, 2 * N - 1, N, board);
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < 2 * N - 1; j++)
            cout << board[i][j];
        cout << '\n';
    }
}