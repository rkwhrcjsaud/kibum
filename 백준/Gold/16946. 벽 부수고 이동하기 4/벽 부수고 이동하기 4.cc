#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <map>
#include <set>

using namespace std;

int N, M;
vector<vector<int> > board;
vector<int> parent;
vector<vector<int> > zero;
map<int, int> m;
int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int union_find(int a)
{
    if (parent[a] == a)
        return a;
    return parent[a] = union_find(parent[a]);
}

void union_merge(int a, int b)
{
    a = union_find(a);
    b = union_find(b);
    if (a != b)
    {
        if (a > b)
            parent[b] = a;
        else
            parent[a] = b;
    }
}

int dfs(int y, int x)
{
    int ret = 1;
    for (int i = 0; i < 4; i++)
    {
        int ny = y + dir[i][0], nx = x + dir[i][1];
        if (ny < 0 || ny >= N || nx < 0 || nx >= M)
            continue ;
        if (board[ny][nx] == 1)
            continue;
        if (union_find(y * M + x) != union_find(ny * M + nx))
        {
            union_merge(y * M + x, ny * M + nx);
            ret += dfs(ny, nx);
        }
    }
    return ret;
}

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    cin >> N >> M;
    board.resize(N, vector<int>(M));
    zero.resize(N, vector<int>(M));
    parent.resize(N * M);
    for (int i = 0; i < N; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < M; j++)
        {
            board[i][j] = s[j] - '0';
            parent[i * M + j] = i * M + j;
        }
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (board[i][j] == 0 && m.find(union_find(i * M + j)) == m.end())
            {
                int cnt = dfs(i, j);
                m[union_find(i * M + j)] = cnt;
            }
        }
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (board[i][j] == 0)
                cout << '0';
            else
            {
                set<int> s;
                for (int k = 0; k < 4; k++)
                {
                    int ny = i + dir[k][0], nx = j + dir[k][1];
                    if (ny < 0 || ny >= N || nx < 0 || nx >= M)
                        continue ;
                    if (board[ny][nx] == 1)
                        continue ;
                    s.insert(union_find(ny * M + nx));
                }
                int ret = 1;
                for (auto it = s.begin(); it != s.end(); it++)
                    ret += m[*it];
                cout << ret % 10;
            }
        }
        cout << '\n';
    }
}