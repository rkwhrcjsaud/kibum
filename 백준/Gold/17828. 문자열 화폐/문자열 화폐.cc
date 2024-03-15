#include <iostream>

int N, X;

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N >> X;
    if (N * 26 < X || N > X)
    {
        std::cout << "!" << '\n';
        return 0;
    }
    for (int i = 0; i < N; i++)
    {
        if (X - 26 * (N - i - 1) > 0)
        {
            std::cout << (char)('A' + (X - 26 * (N - i - 1) - 1));
            X -= X - 26 * (N - i - 1);
        }
        else
        {
            std::cout << 'A';
            X--;
        }
    }
    std::cout << '\n';
}