#include <iostream>
#include <queue>

int N, M;
int room_cnt, max_room, max_room_plus;
int map[51][51];
int num[51][51];
int room[2510];
int d[4][2] = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};

int bfs(int y, int x, int room)
{
    std::queue<std::pair<int, int> > q;
    q.push(std::make_pair(y, x));
    num[y][x] = room;
    int cnt = 0;
    while (!q.empty())
    {
        int cy = q.front().first;
        int cx = q.front().second;
        q.pop();
        cnt++;
        for (int i = 0; i < 4; i++)
        {
            if (!(map[cy][cx] & (1 << i)))
            {
                int ny = cy + d[i][0];
                int nx = cx + d[i][1];
                if (ny < 0 || ny >= M || nx < 0 || nx >= N || num[ny][nx])
                    continue ;
                num[ny][nx] = room;
                q.push(std::make_pair(ny, nx));
            }
        }
    }
    return (cnt);
}

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N >> M;
    for (int i = 0; i < M; i++)
        for (int j = 0; j < N; j++)
            std::cin >> map[i][j];
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (!num[i][j])
            {
                room_cnt++;
                room[room_cnt] = bfs(i, j, room_cnt);
                max_room = std::max(max_room, room[room_cnt]);
            }
        }
    }
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            for (int k = 0; k < 4; k++)
            {
                if (map[i][j] & (1 << k))
                {
                    int ny = i + d[k][0];
                    int nx = j + d[k][1];
                    if (ny < 0 || ny >= M || nx < 0 || nx >= N)
                        continue ;
                    if (num[i][j] != num[ny][nx])
                        max_room_plus = std::max(max_room_plus, room[num[i][j]] + room[num[ny][nx]]);
                }
            }
        }
    }
    std::cout << room_cnt << '\n' << max_room << '\n' << max_room_plus << '\n';
}