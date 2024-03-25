#include <iostream>

int N, K;
int arr[200002];

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N >> K;
    for (int i = 1; i <= N; i++)
        std::cin >> arr[i];
    int left = -1, right = -1;
    for (int i = 1; i <= N; i++)
    {
        if ((arr[i] | K) == K)
        {
            int tmp = 0;
            left = i;
            do {
                tmp |= arr[i];
                i++;
            } while ((arr[i] | K) == K && i <= N);
            if (tmp == K)
            {
                right = i - 1;
                break ;
            }
            left = -1;
        }
    }
    if (left == -1)
    {
        std::cout << "-1\n";
        return 0;
    }
    std::cout << left << ' ' << right << '\n';
}