#include <iostream>

int N;

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N;
    int total = 0;
    int cnt = 0;
    for (int i = 0; i < N; i++)
    {
        int x;
        std::cin >> x;
        total += x;
        if (x >= 2)
            cnt += x / 2;
    }
    if (total % 3 != 0)
    {
        std::cout << "NO\n";
        return 0;
    }
    if (cnt >= total / 3)
        std::cout << "YES\n";
    else
        std::cout << "NO\n";
}