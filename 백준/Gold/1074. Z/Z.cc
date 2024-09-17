#include <iostream>
#include <string>
#include <string.h>

int N, r, c;
int dir[4][2] = {{0, 0}, {0, 1}, {1, 0}, {1, 1}};

int sol(int y1, int x1, int y2, int x2)
{
    if (y1 > r || r > y2 || x1 > c || c > x2)
        return 0;
    if (y1 == y2 && x1 == x2)
        return 1;
    int tmp = (y2 - y1) * (x2 - x1) / 4;
    int size = 0;
    for (int i = 0; i < 4; i++)
    {
        int ny1 = y1 + (y2 - y1) / 2 * dir[i][0];
        int nx1 = x1 + (x2 - x1) / 2 * dir[i][1];
        int ny2 = ny1 + (y2 - y1) / 2;
        int nx2 = nx1 + (x2 - x1) / 2;
        int ret = sol(ny1, nx1, ny2, nx2);
        if (ret)
            return ret + size;
        size += tmp;
    }
    return 0;
}

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N >> r >> c;
    std::cout << sol(0, 0, (1 << N), (1 << N)) - 1 << '\n';
}