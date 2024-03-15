#include <iostream>

int N;
int arr[20][20];

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            std::cin >> arr[i][j];
    int min = (1 << 19);
    for (int i = 0; i < (1 << N); i++)
    {
        int cnt = 0;
        int tmp[20][20];
        for (int j = 0; j < N; j++)
            for (int k = 0; k < N; k++)
                tmp[j][k] = arr[j][k];
        for (int j = 0; j < N; j++)
        {
            if (i & (1 << j))
            {
                cnt++;
                tmp[0][j] = !tmp[0][j];
                tmp[1][j] = !tmp[1][j];
                if (j > 0)
                    tmp[0][j - 1] = !tmp[0][j - 1];
                if (j < N - 1)
                    tmp[0][j + 1] = !tmp[0][j + 1];
            }
        }
        for (int j = 1; j < N; j++)
        {
            for (int k = 0; k < N; k++)
            {
                if (tmp[j - 1][k])
                {
                    cnt++;
                    tmp[j][k] = !tmp[j][k];
                    tmp[j - 1][k] = !tmp[j - 1][k];
                    if (j < N - 1)
                        tmp[j + 1][k] = !tmp[j + 1][k];
                    if (k > 0)
                        tmp[j][k - 1] = !tmp[j][k - 1];
                    if (k < N - 1)
                        tmp[j][k + 1] = !tmp[j][k + 1];
                }
            }
        }
        bool flag = true;
        for (int j = 0; j < N; j++)
        {
            if (tmp[N - 1][j])
            {
                flag = false;
                break ;
            }
        }
        if (flag && min > cnt)
            min = cnt;
    }
    if (min == (1 << 19))
        std::cout << -1 << '\n';
    else
        std::cout << min << '\n';
}