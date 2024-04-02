#include <iostream>

int N, M;
int ans = 0x7fffffff, cnt;
bool map[8][8];
bool tmp[8][8];
int dydx[9][2] = {{0, 0}, {0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

void toggle(int y, int x)
{
    cnt++;
    for (int i = 0; i < 9; ++i)
    {
        int next_y = y + dydx[i][0];
        int next_x = x + dydx[i][1];
        if (next_y < 0 || next_y >= N || next_x < 0 || next_x >= M)
            continue;
        tmp[next_y][next_x] = !tmp[next_y][next_x];
    }
}

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N >> M;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            char c;
            std::cin >> c;
            if (c == '*')
                map[i][j] = true;
        }
    }
    for (int i = 0; i < (1 << (M + N)); ++i)
    {
        for (int j = 0; j < N; ++j)
            for (int k = 0; k < M; ++k)
                tmp[j][k] = map[j][k];
        cnt = 0;
        for (int j = 0; j < M; ++j)
        {
            if (i & (1 << j))
                toggle(0, j);
        }
        for (int j = 1; j < N; ++j)
        {
            if (i & (1 << (j + M - 1)))
                toggle(j, 0);
            for (int k = 1; k < M; ++k)
            {
                if (!tmp[j - 1][k - 1])
                    toggle(j, k);
            }
        }
        bool flag = true;
        for (int j = 0; j < N; ++j)
            for (int k = 0; k < M; ++k)
                if (!tmp[j][k])
                    flag = false;
        if (flag)
            ans = std::min(ans, cnt);
    }
    if (ans == 0x7fffffff)
        std::cout << -1 << '\n';
    else
        std::cout << ans << '\n';
}