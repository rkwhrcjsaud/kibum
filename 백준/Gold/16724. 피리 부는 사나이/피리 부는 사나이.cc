#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#include <cmath>

using namespace std;

int N, M;
vector<int> parent;
vector<string> board;
vector<int> dir(4);
char dir_char[4] = {'U', 'D', 'L', 'R'};

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
        parent[a] = b;
}

void dfs(int num)
{
    int y = num / M, x = num % M;
    for (int i = 0; i < 4; i++)
    {
        if (board[y][x] == dir_char[i])
        {
            if (union_find(num) != union_find(num + dir[i]))
            {
                union_merge(num, num + dir[i]);
                dfs(num + dir[i]);
                break ;
            }
        }
    }
}

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    cin >> N >> M;
    parent.resize(N * M);
    board.resize(N);
    dir[0] = -M, dir[1] = M, dir[2] = -1, dir[3] = 1;
    for (int i = 0; i < N; i++)
        cin >> board[i];
    for (int i = 0; i < N * M; i++)
        parent[i] = i;
    for (int i = 0; i < N * M; i++)
        dfs(i);
    int cnt = 0;
    for (int i = 0; i < N * M; i++)
        if (parent[i] == i)
            cnt++;
    cout << cnt << '\n';
}