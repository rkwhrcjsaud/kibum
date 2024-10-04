#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#include <cmath>

using namespace std;

int N, M;
int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

struct POS
{
    int y, x;
    POS(int y, int x) : y(y), x(x) {}
};

POS Red(0, 0), Blue(0, 0);

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    cin >> N >> M;
    vector<vector<char> > v(N, vector<char>(M));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> v[i][j];
            if (v[i][j] == 'R')
            {
                Red = POS(i, j);
                v[i][j] = '.';
            }
            else if (v[i][j] == 'B')
            {
                Blue = POS(i, j);
                v[i][j] = '.';
            }
        }
    }
    queue<pair<pair<POS, POS>, pair<int, int> > > q;
    q.push(make_pair(make_pair(Red, Blue), make_pair(0, -1)));
    while (!q.empty())
    {
        POS red = q.front().first.first;
        POS blue = q.front().first.second;
        int cnt = q.front().second.first;
        int prev = q.front().second.second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            if (i == prev)
                continue ;
            POS nextRed = red;
            POS nextBlue = blue;
            int nextCnt = cnt + 1;
            int redMove = 0;
            int blueMove = 0;
            bool redIn = false;
            bool blueIn = false;
            while (1)
            {
                int nextRedY = nextRed.y + dir[i][0];
                int nextRedX = nextRed.x + dir[i][1];
                redMove++;
                if (v[nextRedY][nextRedX] == '#')
                {
                    redMove--;
                    break ;
                }
                if (v[nextRedY][nextRedX] == 'O')
                {
                    redIn = true;
                    break ;
                }
                nextRed.y = nextRedY;
                nextRed.x = nextRedX;
            }
            while (1)
            {
                int nextBlueY = nextBlue.y + dir[i][0];
                int nextBlueX = nextBlue.x + dir[i][1];
                blueMove++;
                if (v[nextBlueY][nextBlueX] == '#')
                {
                    blueMove--;
                    break ;
                }
                if (v[nextBlueY][nextBlueX] == 'O')
                {
                    blueIn = true;
                    break ;
                }
                nextBlue.y = nextBlueY;
                nextBlue.x = nextBlueX;
            }
            if (blueIn)
                continue ;
            if (redIn)
            {
                cout << nextCnt << '\n';
                return 0;
            }
            if (nextRed.y == nextBlue.y && nextRed.x == nextBlue.x)
            {
                if (redMove > blueMove)
                {
                    nextRed.y -= dir[i][0];
                    nextRed.x -= dir[i][1];
                }
                else
                {
                    nextBlue.y -= dir[i][0];
                    nextBlue.x -= dir[i][1];
                }
            }
            if (nextCnt < 10)
                q.push(make_pair(make_pair(nextRed, nextBlue), make_pair(nextCnt, (i & 1 ? i - 1 : i + 1))));
        }
    }
    cout << -1 << '\n';
}