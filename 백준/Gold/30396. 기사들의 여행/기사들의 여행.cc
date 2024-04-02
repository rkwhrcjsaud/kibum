#include <iostream>
#include <queue>
#include <vector>

int s, e;
int dydx[8][2] = {{-2, -1}, {-2, 1}, {-1, -2}, {-1, 2}, {1, -2}, {1, 2}, {2, -1}, {2, 1}};
int visited[1 << 16];

int move(int cur, int idx, int dir)
{
    int x = idx % 4;
    int y = idx / 4;
    int nx = x + dydx[dir][0];
    int ny = y + dydx[dir][1];
    if (nx < 0 || nx >= 4 || ny < 0 || ny >= 4)
        return -1;
    int nidx = ny * 4 + nx;
    if (cur & (1 << nidx))
        return -1;
    cur ^= (1 << idx);
    cur |= (1 << nidx);
    return cur;
}

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::fill(&visited[0], &visited[(1 << 16)], -1);
    for (int i = 0; i < 4; i++)
    {
        std::string str;
        std::cin >> str;
        for (int j = 0; j < 4; j++)
        {
            if (str[j] == '1')
                s |= (1 << (i * 4 + j));
        }
    }
    for (int i = 0; i < 4; i++)
    {
        std::string str;
        std::cin >> str;
        for (int j = 0; j < 4; j++)
        {
            if (str[j] == '1')
                e |= (1 << (i * 4 + j));
        }
    }
    visited[s] = 0;
    std::queue<int> q;
    q.push(s);
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        if (cur == e)
            break ;
        for (int i = 0; i < 16; i++)
        {
            if (!(cur & (1 << i)))
                continue ;
            for (int j = 0; j < 8; j++)
            {
                int next = move(cur, i, j);
                if (next == -1 || visited[next] != -1)
                    continue ;
                visited[next] = visited[cur] + 1;
                q.push(next);
            }
        }
    }
    std::cout << visited[e] << '\n';
}