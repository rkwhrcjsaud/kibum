#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

int map[5][5];
std::vector< std::pair<int, int> > v;
std::vector< int > order;
int start_x, start_y;
int dydx[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int startToDest[6];
int destToDest[6][6];
int visited[5][5];
int ans;

void calc(std::pair<int, int> s)
{
    std::queue< std::pair<int, int> > q;
    std::fill(&visited[0][0], &visited[4][5], -1);
    q.push(std::make_pair(start_x, start_y));
    visited[start_x][start_y] = 0;
    while(!q.empty())
    {
        std::pair<int, int> cur = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int next_x = cur.first + dydx[i][0];
            int next_y = cur.second + dydx[i][1];
            if (next_x < 0 || next_x >= 5 || next_y < 0 || next_y >= 5)
                continue;
            if (visited[next_x][next_y] != -1 || map[next_x][next_y] == -1)
                continue;
            visited[next_x][next_y] = visited[cur.first][cur.second] + 1;
            q.push(std::make_pair(next_x, next_y));
        }
    }
}

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            std::cin >> map[i][j];
            if (map[i][j] > 0)
                v.push_back(std::make_pair(i, j));
        }
    }
    std::cin >> start_x >> start_y;
    calc(std::make_pair(start_x, start_y));
    for (int i = 0; i < v.size(); i++)
    {
        startToDest[i] = visited[v[i].first][v[i].second];
        if (startToDest[i] == -1)
        {
            std::cout << -1 << '\n';
            return 0;
        }
    }
    for (int i = 0; i < v.size() - 1; i++)
    {
        for (int j = i + 1; j < v.size(); j++)
        {
            if (i == j)
                continue;
            start_x = v[i].first;
            start_y = v[i].second;
            calc(v[j]);
            destToDest[i][j] = visited[v[j].first][v[j].second];
            destToDest[j][i] = visited[v[j].first][v[j].second];
            if (destToDest[i][j] == -1)
            {
                std::cout << -1 << '\n';
                return 0;
            }
        }
    }
    for (int i = 0; i < 6; i++)
        order.push_back(i);
    do
    {
        int sum = startToDest[order[0]];
        for (int i = 0; i < order.size() - 1; i++)
            sum += destToDest[order[i]][order[i + 1]];
        if (ans == 0 || ans > sum)
            ans = sum;
    } while (std::next_permutation(order.begin(), order.end()));
    std::cout << ans << '\n';
}