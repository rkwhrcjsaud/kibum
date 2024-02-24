#include <iostream>

int M, N;
int flag[1001][1001];

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> M >> N;
    std::string arr[M];
    for (int i = 0; i < M; i++)
        std::cin >> arr[i];
    int cnt = 0;
    for (int i = 1; i < M - 1; i++)
    {
        for (int j = 1; j < N - 1; j++)
        {
            if (arr[i][j] == '.')
            {
                if (arr[i - 1][j] == 'X' && arr[i][j + 1] == '.' && arr[i - 1][j + 1] == 'X'
                    && (flag[i][j] & 1) == 0 && (flag[i][j + 1] & 1) == 0)
                {
                    flag[i][j] |= 1;
                    flag[i][j + 1] |= 1;
                    cnt++;
                }
                if (arr[i + 1][j] == 'X' && arr[i][j + 1] == '.' && arr[i + 1][j + 1] == 'X'
                    && (flag[i][j] & 2) == 0 && (flag[i][j + 1] & 2) == 0)
                {
                    flag[i][j] |= 2;
                    flag[i][j + 1] |= 2;
                    cnt++;
                }
                if (arr[i][j - 1] == 'X' && arr[i + 1][j] == '.' && arr[i + 1][j - 1] == 'X'
                    && (flag[i][j] & 4) == 0 && (flag[i + 1][j] & 4) == 0)
                {
                    flag[i][j] |= 4;
                    flag[i + 1][j] |= 4;
                    cnt++;
                }
                if (arr[i][j + 1] == 'X' && arr[i + 1][j] == '.' && arr[i + 1][j + 1] == 'X'
                    && (flag[i][j] & 8) == 0 && (flag[i + 1][j] & 8) == 0)
                {
                    flag[i][j] |= 8;
                    flag[i + 1][j] |= 8;
                    cnt++;
                }
            }
        }
    }
    std::cout << cnt << '\n';
}