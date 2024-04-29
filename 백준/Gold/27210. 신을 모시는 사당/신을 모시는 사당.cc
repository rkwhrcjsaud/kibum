#include <iostream>
#include <vector>
#include <algorithm>

int N;
int arr[100001];

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N;
    for (int i = 1; i <= N; i++)
    {
        int tmp;
        std::cin >> tmp;
        if (tmp == 1)
            arr[i] = arr[i - 1] + 1;
        else
            arr[i] = arr[i - 1] - 1;
    }
    std::sort(arr, arr + N + 1);
    std::cout << std::abs(arr[N] - arr[0]) << '\n';
}
