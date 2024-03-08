#include <iostream>

int N;
int arr[370];

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N;
    for (int i = 0; i < N; i++)
    {
        int s, e;
        std::cin >> s >> e;
        for (int i = s; i <= e; i++)
            arr[i]++;
    }
    int sum = 0;
    for (int i = 1; i <= 365; i++)
    {
        if (arr[i] == 0)
            continue;
        int j = i;
        int max = 0;
        while (arr[i] != 0)
        {
            max = std::max(max, arr[i]);
            i++;
        }
        sum += max * (i - j);
    }
    std::cout << sum << '\n';
}
