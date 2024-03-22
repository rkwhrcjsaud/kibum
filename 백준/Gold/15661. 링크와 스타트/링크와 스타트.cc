#include <iostream>

int N;
int min_diff = 0x7fffffff;
int map[21][21];

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            std::cin >> map[i][j];
    for (int i = 0; i < (1 << (N - 1)); i++)
    {
        int cnt = 0;
        for (int j = 0; j < N; j++)
            if (i & (1 << j))
                cnt++;
        if (cnt > 0 && cnt < N)
        {
            int start = 0;
            int link = 0;
            for (int j = 0; j < N; j++)
            {
                for (int k = 0; k < N; k++)
                {
                    if (i & (1 << j) && i & (1 << k))
                        start += map[j][k];
                    if (!(i & (1 << j)) && !(i & (1 << k)))
                        link += map[j][k];
                }
            }
            min_diff = std::min(min_diff, abs(start - link));
        }
    }
    std::cout << min_diff << '\n';
}