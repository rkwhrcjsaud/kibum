#include <iostream>

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    int R, C;
    std::cin >> R >> C;
    int cur = 1, down = 2, right = 3;
    long long cnt = 1;
    for (int x = 1, y = 1;;)
    {
        int tmp;
        x += (C - 1) / 4 * 4;
        cnt += 14 * ((C - 1) / 4);
        while (x < C)
        {
            tmp = cur;
            cur = 7 - right;
            right = tmp;
            cnt += cur;
            x++;
        }
        if (y == R)
            break ;
        y++;
        tmp = cur;
        cur = 7 - down;
        down = tmp;
        cnt += cur;
        x -= (C - 1) / 4 * 4;
        cnt += 14 * ((C - 1) / 4);
        while (x > 1)
        {
            tmp = cur;
            cur = right;
            right = 7 - tmp;
            cnt += cur;
            x--;
        }
        if (y == R)
            break ;
        y++;
        tmp = cur;
        cur = 7 - down;
        down = tmp;
        cnt += cur;
    }
    std::cout << cnt << '\n';
}