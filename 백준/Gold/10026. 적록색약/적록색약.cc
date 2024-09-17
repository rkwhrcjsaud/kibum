#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#include <map>

using namespace std;

string board[101];
int parent_nomal[10001];
int parent_abnormal[10001];
int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int find_parent_nomal(int x)
{
    if (parent_nomal[x] == x)
        return x;
    return parent_nomal[x] = find_parent_nomal(parent_nomal[x]);
}

int find_parent_abnormal(int x)
{
    if (parent_abnormal[x] == x)
        return x;
    return parent_abnormal[x] = find_parent_abnormal(parent_abnormal[x]);
}

void union_parent_nomal(int a, int b)
{
    a = find_parent_nomal(a);
    b = find_parent_nomal(b);
    if (a < b)
        parent_nomal[b] = a;
    else
        parent_nomal[a] = b;
}

void union_parent_abnormal(int a, int b)
{
    a = find_parent_abnormal(a);
    b = find_parent_abnormal(b);
    if (a < b)
        parent_abnormal[b] = a;
    else
        parent_abnormal[a] = b;
}

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> board[i];
        for (int j = 0; j < N; j++)
        {
            parent_nomal[i * N + j] = i * N + j;
            parent_abnormal[i * N + j] = i * N + j;
        }
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            for (int k = 0; k < 4; k++)
            {
                int ny = i + dir[k][0];
                int nx = j + dir[k][1];
                if (ny < 0 || ny >= N || nx < 0 || nx >= N)
                    continue ;
                if (board[i][j] == board[ny][nx])
                {
                    union_parent_nomal(i * N + j, ny * N + nx);
                    union_parent_abnormal(i * N + j, ny * N + nx);
                }
                else if (board[i][j] == 'R' && board[ny][nx] == 'G')
                    union_parent_abnormal(i * N + j, ny * N + nx);
                else if (board[i][j] == 'G' && board[ny][nx] == 'R')
                    union_parent_abnormal(i * N + j, ny * N + nx);
            }
        }
    }
    int nomal = 0;
    int abnormal = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (parent_nomal[i * N + j] == i * N + j)
                nomal++;
            if (parent_abnormal[i * N + j] == i * N + j)
                abnormal++;
        }
    }
    cout << nomal << ' ' << abnormal << '\n';
}