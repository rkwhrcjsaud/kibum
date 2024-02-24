#include <iostream>

std::string arr[9];
int max;

void solution(int y, int x, int depth)
{
    if (depth == max)
    {
        for (int i = 0; i < 9; i++)
            std::cout << arr[i] << '\n';
        exit(0);
    }
    if (arr[y][x] != '0')
    {
        if (x == 8)
            solution(y + 1, 0, depth);
        else
            solution(y, x + 1, depth);
        return ;
    }
    for (int k = 1; k <= 9; k++)
    {
        bool flag = false;
        for (int l = 0; l < 9; l++)
        {
            if (arr[y][l] == k + '0' || arr[l][x] == k + '0')
            {
                flag = true;
                break ;
            }
        }
        for (int l = (y / 3) * 3; l < (y / 3) * 3 + 3; l++)
        {
            for (int m = (x / 3) * 3; m < (x / 3) * 3 + 3; m++)
            {
                if (arr[l][m] == k + '0')
                {
                    flag = true;
                    break ;
                }
            }
        }
        if (flag)
            continue ;
        arr[y][x] = k + '0';
        if (x == 8)
            solution(y + 1, 0, depth + 1);
        else
            solution(y, x + 1, depth + 1);
        arr[y][x] = '0';
    }
}

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    for (int i = 0; i < 9; i++)
        std::cin >> arr[i];
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (arr[i][j] == '0')
                max++;
        }
    }
    solution(0, 0, 0);
}