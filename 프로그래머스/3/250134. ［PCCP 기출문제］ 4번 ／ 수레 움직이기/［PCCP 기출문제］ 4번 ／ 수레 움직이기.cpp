#include <string>
#include <vector>
#include <queue>

using namespace std;

// 8 = red가 지나간자리 flag, 16 = blue가 지나간자리 flag
int n, m;
int dir[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

struct S{
    vector<vector<int>> m;
    int red_x;
    int red_y;
    int blue_x;
    int blue_y;
    int turn;
    bool red_clear;
    bool blue_clear;
};

queue<S> q;

int solution(vector<vector<int>> maze) {
    int answer = 0;

    n = maze.size();
    m = maze[0].size();
    
    S start;
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (maze[i][j] == 1)
            {
                start.red_y = i;
                start.red_x = j;
                maze[i][j] |= 8;
            }
            if (maze[i][j] == 2)
            {
                start.blue_y = i;
                start.blue_x = j;
                maze[i][j] |= 16;
            }
        }
    }
    
    start.red_clear = false;
    start.blue_clear = false;
    start.m = maze;
    start.turn = 0;
    
    q.push(start);
    while (!q.empty())
    {
        S cur = q.front();
        q.pop();
        if (cur.red_clear && cur.blue_clear)
            return cur.turn;
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                S next;
                next.m = cur.m;
                next.red_x = cur.red_x + (cur.red_clear ? 0 : dir[i][0]);
                next.red_y = cur.red_y + (cur.red_clear ? 0 : dir[i][1]);
                next.blue_x = cur.blue_x + (cur.blue_clear ? 0 : dir[j][0]);
                next.blue_y = cur.blue_y + (cur.blue_clear ? 0 : dir[j][1]);
                next.blue_clear = cur.blue_clear;
                next.red_clear = cur.red_clear;
                next.turn = cur.turn + 1;
                if (next.red_x >= m || next.red_x < 0)
                    continue;
                if (next.red_y >= n || next.red_y < 0)
                    continue;
                if (next.blue_x >= m || next.blue_x < 0)
                    continue;
                if (next.blue_y >= n || next.blue_y < 0)
                    continue;
                // swap
                if (next.red_x == cur.blue_x && next.red_y == cur.blue_y && \
                   next.blue_x == cur.red_x && next.blue_y == cur.red_y)
                    continue;
                // clash
                if (next.red_x == next.blue_x && next.red_y == next.blue_y)
                    continue;
                int &red = next.m[next.red_y][next.red_x];
                int &blue = next.m[next.blue_y][next.blue_x];
                // wall
                if ((red & 5) == 5 || (blue & 5) == 5)
                    continue;
                // prev
                if ((red & 8) || (blue & 16))
                    continue;
                if (red == 3 || red == 19 || next.red_clear)
                    next.red_clear = true;
                else
                    red |= 8;
                if (blue == 4 || blue == 12 || next.blue_clear)
                    next.blue_clear = true;
                else
                    blue |= 16;
                q.push(next);
            }
        }
    }
    
    return answer;
}