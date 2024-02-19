#include <iostream>

int arr[100010];

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    int N, max = 0;
    std::cin >> N;
    for (int i = 0; i < N; i++)
    {
        int tmp;
        std::cin >> tmp;
        ++arr[tmp] > max ? max = arr[tmp] : 0;
    }
    if (max <= (N + 1) / 2)
        std::cout << "YES\n";
    else
        std::cout << "NO\n";
}