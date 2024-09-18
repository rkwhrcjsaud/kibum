#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#include <map>

using namespace std;

int N, M;
string arr[601];
int start_x, start_y;
int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        string s;
        cin >> s;
        arr[i] = s;
        if (s.find("I") != string::npos)
        {
            start_x = i;
            start_y = s.find("I");
        }
    }
    queue<pair<int, int> > q;
    q.push(make_pair(start_x, start_y));
    vector<vector<bool> > visited(N, vector<bool>(M, false));
    int ret = 0;
    while (!q.empty())
    {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        if (visited[y][x])
            continue ;
        visited[y][x] = true;
        if (arr[y][x] == 'P')
            ret++;
        arr[y][x] = 'X';
        for (int i = 0; i < 4; i++)
        {
            int ny = y + dir[i][0];
            int nx = x + dir[i][1];
            if (ny < 0 || ny >= N || nx < 0 || nx >= M || arr[ny][nx] == 'X')
                continue ;
            q.push(make_pair(ny, nx));
        }
    }
    if (ret == 0)
        cout << "TT\n";
    else
        cout << ret << '\n';
}