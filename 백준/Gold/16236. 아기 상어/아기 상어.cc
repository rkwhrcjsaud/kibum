#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

int N;
vector<vector<int> > board;
int start_x, start_y;
int dir[4][2] = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    cin >> N;
    board.resize(N, vector<int>(N, 0));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> board[i][j];
            if (board[i][j] == 9)
            {
                start_y = i;
                start_x = j;
                board[i][j] = 0;
            }
        }
    }
    int size = 2;
    int cnt = 0;
    int ret = 0;
    while (true)
    {
        queue<pair<int, int> > q;
        vector<vector<bool> > visited(N, vector<bool>(N, false));
        q.push(make_pair(start_y, start_x));
        visited[start_y][start_x] = true;
        int dist = 0;
        vector<pair<int, int> > eat;
        while (!q.empty())
        {
            int q_size = q.size();
            for (int i = 0; i < q_size; i++)
            {
                int hereY = q.front().first;
                int hereX = q.front().second;
                q.pop();
                for (int j = 0; j < 4; j++)
                {
                    int thereY = hereY + dir[j][0];
                    int thereX = hereX + dir[j][1];
                    if (thereY < 0 || thereY >= N || thereX < 0 || thereX >= N)
                        continue;
                    if (board[thereY][thereX] <= size && !visited[thereY][thereX])
                    {
                        q.push(make_pair(thereY, thereX));
                        visited[thereY][thereX] = true;
                        if (board[thereY][thereX] != 0 && board[thereY][thereX] < size)
                            eat.push_back(make_pair(thereY, thereX));
                    }
                }
            }
            dist++;
            if (eat.size() != 0)
                break;
        }
        if (eat.size() == 0)
            break;
        sort(eat.begin(), eat.end());
        start_y = eat[0].first;
        start_x = eat[0].second;
        board[start_y][start_x] = 0;
        cnt++;
        if (cnt == size)
        {
            size++;
            cnt = 0;
        }
        ret += dist;
    }
    cout << ret << '\n';
}