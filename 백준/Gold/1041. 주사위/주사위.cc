#include <iostream>

long long N;
int arr[10];

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N;
    for (int i = 0; i < 6; i++)
        std::cin >> arr[i];
    long long three = 200, two = 100, one = 100;
    int max = 0;
    int total = 0;
    for (int i = 0; i < 6; i++)
    {
        if (arr[i] < one)
            one = arr[i];
        total += arr[i];
        if (arr[i] > max)
            max = arr[i];
        for (int j = 0; j < 6; j++)
        {
            if (i == j || i + j == 5)
                continue;
            if (arr[i] + arr[j] < two)
                two = arr[i] + arr[j];
            for (int k = 0; k < 6; k++)
            {
                if (i == j || j == k || k == i
                    || i + j == 5 || j + k == 5 || k + i == 5)
                    continue;
                if (arr[i] + arr[j] + arr[k] < three)
                    three = arr[i] + arr[j] + arr[k];
            }
        }
    }
    if (N == 1)
    {
        std::cout << total - max << '\n';
        return 0;
    }
    std::cout << three * 4 + two * ((N - 1) * 4 + (N - 2) * 4) + one * ((N - 1) * (N - 2) * 4 + (N - 2) * (N - 2)) << '\n';
}
