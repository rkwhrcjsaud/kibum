#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

int N;
int arr[10];

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N;
    for (int i = 0; i < N; i++)
    {
        int num;
        std::cin >> num;
        arr[num % 7]++;
    }
    int bit = (1 << 3);
    for (int i = 1; i < 7; i++)
    {
        int tmpbit = 0;
        for (int j = i; j <= arr[i] * i; j += i)
        {
            if (tmpbit & (1 << (j % 7)))
                break ;
            tmpbit |= (1 << (j % 7));
        }
        int ansbit = 0;
        for (int j = 0; j < 7; j++)
        {
            if (!(tmpbit & (1 << j)))
                continue ;
            for (int k = 0; k < 7; k++)
            {
                if (!(bit & (1 << k)))
                    continue ;
                ansbit |= (1 << ((j + k) % 7));
            }
        }
        bit |= ansbit;
        if (bit & 1)
        {
            std::cout << "YES\n";
            return 0;
        }
    }
    std::cout << "NO\n";
}
