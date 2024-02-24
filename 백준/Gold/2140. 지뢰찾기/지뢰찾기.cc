#include <iostream>

int N;
int dir[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}};

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N;
    std::string arr[N];
    for (int i = 0; i < N; i++)
        std::cin >> arr[i];
    int cnt = 0;
    for (int i = 1; i < N - 1; i++)
    {
        for (int j = 1; j < N - 1; j++)
        {
            int k = 0;
            for (; k < 8; k++)
            {
                if (arr[i + dir[k][0]][j + dir[k][1]] == '0')
                    break ;
            }
            if (k == 8)
            {
                cnt++;
                for (int k = 0; k < 8; k++)
                {
                    if (arr[i + dir[k][0]][j + dir[k][1]] != '#')
                        arr[i + dir[k][0]][j + dir[k][1]] -= 1;
                }
            }
        }
    }
    std::cout << cnt << '\n';
}