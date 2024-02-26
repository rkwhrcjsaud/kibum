#include <iostream>

int N;
int a[410][410];
int b[410][410];

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            int tmp;
            std::cin >> tmp;
            a[i][j] = a[i - 1][j - 1] + tmp;
            b[i][j] = b[i - 1][j + 1] + tmp;
        }
    }
    int max = -1000000000;
    for (int i = 2; i <= N; i++)
    {
        for (int j = 1; j <= N - i + 1; j++)
        {
            for (int k = 1; k <= N - i + 1; k++)
            {
                int a1 = a[j + i - 1][k + i - 1] - a[j - 1][k - 1];
                int b1 = b[j + i - 1][k] - b[j - 1][k + i];
                if (max < a1 - b1)
                    max = a1 - b1;
            }
        }
    }
    std::cout << max << '\n';
}