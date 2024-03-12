#include <iostream>

int N;
int arr[300];

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N;
    for (int i = 1; i <= N; i++)
        std::cin >> arr[i];
    int ans = 0;
    for (int i = 1; i < N; i++)
    {
        int max = 0;
        for (int j = 1; j <= N; j++)
        {
            if (arr[j] > arr[max])
                max = j;
        }
        ans += arr[max - 1] > arr[max + 1] ? arr[max] - arr[max - 1] : arr[max] - arr[max + 1];
        arr[max] = 0;
        for (int j = max; j <= N; j++)
            arr[j] = arr[j + 1];
    }
    std::cout << ans << '\n';
}