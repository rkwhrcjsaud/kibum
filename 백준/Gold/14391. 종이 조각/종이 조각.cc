#include <iostream>

int N, M;
int max;
std::string map[5];

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N >> M;
    for (int i = 0; i < N; i++)
        std::cin >> map[i];
    for (int i = 0; i < (1 << (N * M)); i++)
    {
        int sum = 0;
        for (int j = 0; j < N; j++)
        {
            int tmp1 = 0;
            for (int k = 0; k < M; k++)
            {
                if (i & (1 << (j * M + k)))
                    tmp1 = tmp1 * 10 + map[j][k] - '0';
                else
                {
                    sum += tmp1;
                    tmp1 = 0;
                }
            }
            sum += tmp1;
        }
        for (int j = 0; j < M; j++)
        {
            int tmp2 = 0;
            for (int k = 0; k < N; k++)
            {
                if (!(i & (1 << (k * M + j))))
                    tmp2 = tmp2 * 10 + map[k][j] - '0';
                else
                {
                    sum += tmp2;
                    tmp2 = 0;
                }
            }
            sum += tmp2;
        }
        max = std::max(max, sum);
    }
    std::cout << max << '\n';
}