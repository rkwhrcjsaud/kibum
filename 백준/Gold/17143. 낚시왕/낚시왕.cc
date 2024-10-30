#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <map>
#include <set>

using namespace std;

int R, C, M;
class Shark
{
    public:
        int r, c, s, d, z;
        bool is_alive = false;
        Shark(int r, int c, int s, int d, int z) : r(r), c(c), s(s), d(d), z(z) {}
        Shark() : r(0), c(0), s(0), d(0), z(0) {}
};
vector<Shark> sharks;
int board[101][101];
int dir[5][2] = {{0, 0}, {-1, 0}, {1, 0}, {0, 1}, {0, -1}};

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    cin >> R >> C >> M;
    sharks.reserve(M + 1);
    memset(board, 0, sizeof(board));
    for (int i = 1; i <= M; i++)
    {
        cin >> sharks[i].r >> sharks[i].c >> sharks[i].s >> sharks[i].d >> sharks[i].z;
        sharks[i].is_alive = true;
        board[sharks[i].r][sharks[i].c] = i;
    }
    int ret = 0;
    for (int i = 1; i <= C; i++)
    {
        for (int j = 1; j <= R; j++)
        {
            if (board[j][i])
            {
                sharks[board[j][i]].is_alive = false;
                ret += sharks[board[j][i]].z;
                board[j][i] = 0;
                break ;
            }
        }
        int board_copy[101][101];
        memset(board_copy, 0, sizeof(board_copy));
        for (int j = 1; j <= M; j++)
        {
            if (!sharks[j].is_alive)
                continue ;
            int r = sharks[j].r, c = sharks[j].c, s = sharks[j].s, d = sharks[j].d, z = sharks[j].z;
            int len = s;
            if (d == 1 || d == 2)
                len %= (R - 1) * 2;
            else if (d == 3 || d == 4)
                len %= (C - 1) * 2;
            while (len--)
            {
                int ny = r + dir[d][0], nx = c + dir[d][1];
                if (ny < 1 || ny > R || nx < 1 || nx > C)
                {
                    if (d % 2)
                        d++;
                    else
                        d--;
                    ny = r + dir[d][0], nx = c + dir[d][1];
                }
                r = ny, c = nx;
            }
            sharks[j].r = r, sharks[j].c = c, sharks[j].d = d;
            if (board_copy[r][c])
            {
                if (sharks[board_copy[r][c]].z < z)
                {
                    sharks[board_copy[r][c]].is_alive = false;
                    board_copy[r][c] = j;
                }
                else
                    sharks[j].is_alive = false;
            }
            else
                board_copy[r][c] = j;
        }
        memcpy(board, board_copy, sizeof(board));
    }
    cout << ret << '\n';
}