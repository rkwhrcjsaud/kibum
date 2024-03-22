#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

int N, M;
char map[51][51];
std::vector<std::pair<int, int> > X;
std::vector<int> X_order;
int startTo[6];
int toEnd[6];
int XtoX[6][6];
int visited[51][51];
int d[4][2] = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};

void calc_dist(int y, int x)
{
    std::fill(&visited[0][0], &visited[50][50], -1);
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
            if (ny < 0 || ny >= M || nx < 0 || nx >= N || map[ny][nx] == '#' || visited[ny][nx] != -1)
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
    int start_x, start_y;
    int end_x, end_y;
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            std::cin >> map[i][j];
            if (map[i][j] == 'S')
            {
                start_x = j;
                start_y = i;
            }
            if (map[i][j] == 'E')
            {
                end_x = j;
                end_y = i;
            }
            if (map[i][j] == 'X')
                X.push_back(std::make_pair(i, j));
        }
    }
    calc_dist(start_y, start_x);
    for (int i = 0; i < (int)X.size(); i++)
        startTo[i] = visited[X[i].first][X[i].second];
    calc_dist(end_y, end_x);
    for (int i = 0; i < (int)X.size(); i++)
        toEnd[i] = visited[X[i].first][X[i].second];
    for (int i = 0; i < (int)X.size(); i++)
    {
        for (int j = 0; j < (int)X.size(); j++)
        {
            if (i == j)
                continue ;
            calc_dist(X[i].first, X[i].second);
            XtoX[i][j] = visited[X[j].first][X[j].second];
        }
        X_order.push_back(i);
    }
    int min = 0x7fffffff;
    if (X_order.size() == 0)
    {
        std::cout << visited[start_y][start_x] << '\n';
        return (0);
    }
    do
    {
        int sum = startTo[X_order[0]] + toEnd[X_order[(int)X.size() - 1]];
        for (int i = 0; i < (int)X.size() - 1; i++)
            sum += XtoX[X_order[i]][X_order[i + 1]];
        min = std::min(min, sum);
    } while (std::next_permutation(X_order.begin(), X_order.end()));
    std::cout << min << '\n';
}
