#include <iostream>

int N;
bool map[1000][1000];
bool map2[1000][1000];

void toggle(int y, int x)
{
    if (y > 0)
        map2[y - 1][x] = !map2[y - 1][x];
    if (x > 0)
        map2[y][x - 1] = !map2[y][x - 1];
    if (y < N - 1)
        map2[y + 1][x] = !map2[y + 1][x];
    if (x < N - 1)
        map2[y][x + 1] = !map2[y][x + 1];
}

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N;
    for (int i = 0; i < N; i++)
    {
        char c;
        std::cin >> c;
        if (c == '#')
        {
            map[0][i] = true;
            toggle(0, i);
        }
    }
    for (int i = 1; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (map2[i - 1][j])
            {
                map[i][j] = true;
                toggle(i, j);
            }
        }
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            std::cout << (map[i][j] ? '#' : '.');
        std::cout << '\n';
    }
}