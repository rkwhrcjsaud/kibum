#include <iostream>

bool arr[9][9];
int N;

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            std::cin >> arr[i][j];
    int ans = 0x7fffffff;
    for (int i = 0; i < (1 << (N * 2)); i++)
    {
        bool tmp[9][9];
        int cnt = 0;
        for (int j = 0; j < N; j++)
            for (int k = 0; k < N; k++)
                tmp[j][k] = arr[j][k];
        for (int j = 0; j < N; j++)
        {
            if (i & (1 << j))
            {
                for (int k = 0; k < N; k++)
                    tmp[j][k] = !tmp[j][k];
                cnt++;
            }
        }
        for (int j = 0; j < N; j++)
        {
            if (i & (1 << (j + N)))
            {
                for (int k = 0; k < N; k++)
                    tmp[k][j] = !tmp[k][j];
                cnt++;
            }
        }
        int black = 0;
        int white = 0;
        for (int j = 0; j < N; j++)
        {
            for (int k = 0; k < N; k++)
            {
                if (!tmp[j][k])
                    white++;
                else
                    black++;
            }
        }
        ans = std::min(ans, cnt + std::min(black, white));
    }
    std::cout << ans << '\n';
}