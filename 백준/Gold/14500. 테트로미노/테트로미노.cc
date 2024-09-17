#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#include <map>

using namespace std;

int N, M;
int dir2[4][3][2] = {
    {{1, 0}, {1, 1}, {2, 0}},
    {{1, 0}, {1, -1}, {2, 0}},
    {{0, 1}, {0, 2}, {1, 1}},
    {{1, -1}, {1, 0}, {1, 1}}
};

int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
vector<vector<int> > board(501, vector<int>(501, 0));
vector<vector<bool> > visited(501, vector<bool>(501, false));

int dfs(int y, int x, int cnt)
{
    if (cnt == 4)
        return board[y][x];
    int ret = 0;
    for (int i = 0; i < 4; i++)
    {
        int ny = y + dir[i][0];
        int nx = x + dir[i][1];
        if (ny < 0 || ny >= N || nx < 0 || nx >= M || visited[ny][nx])
            continue ;
        visited[ny][nx] = true;
        ret = max(ret, board[y][x] + dfs(ny, nx, cnt + 1));
        visited[ny][nx] = false;
    }
    return ret;
}

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    cin >> N >> M;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> board[i][j];
    int ret = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            visited[i][j] = true;
            ret = max(ret, dfs(i, j, 1));
            visited[i][j] = false;
            for (int k = 0; k < 4; k++)
            {
                int sum = board[i][j];
                bool flag = true;
                for (int l = 0; l < 3; l++)
                {
                    int ny = i + dir2[k][l][0];
                    int nx = j + dir2[k][l][1];
                    if (ny < 0 || ny >= N || nx < 0 || nx >= M)
                    {
                        flag = false;
                        break ;
                    }
                    sum += board[ny][nx];
                }
                if (flag)
                    ret = max(ret, sum);
            }
        }
    }
    cout << ret << '\n';
}