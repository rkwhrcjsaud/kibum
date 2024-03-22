#include <iostream>
#include <queue>
#include <climits>
#include <algorithm>

int N, M, min = 0x7fffffff;
int start_y, start_x;
int d[4][2] = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
char map[21][21];
int visited[21][21];
int startToTrash[12];
int trashToTrash[12][12];
std::vector< std::pair<int, int> > trash;
std::vector<int> trash_order;

void calc_dist(int y, int x)
{
    std::fill(&visited[0][0], &visited[20][20], INT_MAX);
    visited[y][x] = 0;
    std::queue<std::pair<int, int> > q;
    q.push(std::make_pair(y, x));
    while (!q.empty())
    {
        int cy = q.front().first;
        int cx = q.front().second;
        int cost = visited[cy][cx] + 1;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int ny = cy + d[i][0];
            int nx = cx + d[i][1];
            if (ny < 0 || ny >= M || nx < 0 || nx >= N || map[ny][nx] == 'x' || visited[ny][nx] <= cost)
                continue ;
            visited[ny][nx] = cost;
            q.push(std::make_pair(ny, nx));
        }
    }
}

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N >> M;
    while (N != 0 || M != 0)
    {
        for (int i = 0; i < M; i++)
        {
            for (int j = 0; j < N; j++)
            {
                std::cin >> map[i][j];
                if (map[i][j] == 'o')
                {
                    start_y = i;
                    start_x = j;
                }
                else if (map[i][j] == '*')
                    trash.push_back(std::make_pair(i, j));
            }
        }
        calc_dist(start_y, start_x);
        for (int i = 0; i < (int)trash.size(); i++)
            startToTrash[i] = visited[trash[i].first][trash[i].second];
        for (int i = 0; i < (int)trash.size(); i++)
        {
            calc_dist(trash[i].first, trash[i].second);
            for (int j = 0; j < (int)trash.size(); j++)
            {
                if (i == j)
                    continue ;
                trashToTrash[i][j] = visited[trash[j].first][trash[j].second];
            }
            trash_order.push_back(i);
        }
        do
        {
            int sum = startToTrash[trash_order[0]];
            for (int i = 0; i < (int)trash_order.size() - 1; i++)
            {
                if (trashToTrash[trash_order[i]][trash_order[i + 1]] == INT_MAX)
                {
                    sum = 0x7fffffff;
                    break ;
                }
                sum += trashToTrash[trash_order[i]][trash_order[i + 1]];
            }
            min = std::min(min, sum);
        }
        while (std::next_permutation(trash_order.begin(), trash_order.end()));
        std::cout << (min == 0x7fffffff ? -1 : min) << '\n';
        min = 0x7fffffff;
        trash.clear();
        trash_order.clear();
        std::cin >> N >> M;
    }
}