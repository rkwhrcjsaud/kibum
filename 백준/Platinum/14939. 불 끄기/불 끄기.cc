#include <iostream>

bool arr[15][15];

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            char c;
            std::cin >> c;
            arr[i][j] = (c == 'O');
        }
    }
    int min = 1000000;
    for (int i = 0; i < (1 << 10); i++)
    {
        bool tmp[15][15];
        for (int j = 0; j < 10; j++)
            for (int k = 0; k < 10; k++)
                tmp[j][k] = arr[j][k];
        int cnt = 0;
        for (int j = 0; j < 10; j++)
        {
            if ((i >> j) & 1)
            {
                tmp[0][9 - j] = !tmp[0][9 - j];
                tmp[1][9 - j] = !tmp[1][9 - j];
                if (9 - j > 0)
                    tmp[0][9 - j - 1] = !tmp[0][9 - j - 1];
                if (9 - j < 9)
                    tmp[0][9 - j + 1] = !tmp[0][9 - j + 1];
                cnt++;
            }
        }
        for (int j = 1; j < 10; j++)
        {
            for (int k = 0; k < 10; k++)
            {
                if (tmp[j - 1][k])
                {
                    tmp[j][k] = !tmp[j][k];
                    tmp[j - 1][k] = !tmp[j - 1][k];
                    tmp[j + 1][k] = !tmp[j + 1][k];
                    if (k > 0)
                        tmp[j][k - 1] = !tmp[j][k - 1];
                    if (k < 9)
                        tmp[j][k + 1] = !tmp[j][k + 1];
                    cnt++;
                }
            }
        }
        bool flag = true;
        for (int j = 0; j < 10; j++)
            if (tmp[9][j])
                flag = false;
        if (flag)
        {
            if (min > cnt)
                min = cnt;
        }
    }
    if (min == 1000000)
        std::cout << "-1\n";
    else
        std::cout << min << '\n';
}