#include <iostream>

int arr[10];

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    for (int i = 0; i < 6; i++)
        std::cin >> arr[i];
    int ans = arr[5];
    while (arr[4])
    {
        arr[4]--;
        ans++;
        if (arr[0] >= 11)
            arr[0] -= 11;
        else
            arr[0] = 0;
    }
    while (arr[3])
    {
        arr[3]--;
        ans++;
        if (arr[1] >= 5)
            arr[1] -= 5;
        else
        {
            arr[0] -= 20 - arr[1] * 4;
            arr[1] = 0;
        }
    }
    while (arr[2])
    {
        ans++;
        if (arr[2] >= 4)
            arr[2] -= 4;
        else
        {
            if (arr[2] == 3)
            {
                if (arr[1] >= 1)
                {
                    arr[2] = 0;
                    arr[1] -= 1;
                    arr[0] -= 5;
                }
                else
                {
                    arr[2] = 0;
                    arr[0] -= 9;
                }
            }
            else if (arr[2] == 2)
            {
                if (arr[1] >= 3)
                {
                    arr[2] = 0;
                    arr[1] -= 3;
                    arr[0] -= 6;
                }
                else
                {
                    arr[2] = 0;
                    arr[0] -= 18 - arr[1] * 4;
                    arr[1] = 0;
                }
            }
            else
            {
                if (arr[1] >= 5)
                {
                    arr[2] = 0;
                    arr[1] -= 5;
                    arr[0] -= 7;
                }
                else
                {
                    arr[2] = 0;
                    arr[0] -= 27 - arr[1] * 4;
                    arr[1] = 0;
                }
            }
        }
    }
    while (arr[1] > 0)
    {
        ans++;
        if (arr[1] >= 9)
            arr[1] -= 9;
        else
        {
            arr[0] -= 36 - arr[1] * 4;
            arr[1] = 0;
        }
    }
    while (arr[0] > 0)
    {
        ans++;
        if (arr[0] >= 36)
            arr[0] -= 36;
        else
            arr[0] = 0;
    }
    std::cout << ans << '\n';
}