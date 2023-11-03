#include <iostream>

int N;

int f(int n)
{
    int tmp = 0;
    while (n)
    {
        tmp += n % 10;
        n /= 10;
    }
    if (tmp < 10)
        return tmp;
    return f(tmp);
}

int main(void)
{
    while (1)
    {
        std::cin >> N;
        if (N == 0)
            return 0;
        std::cout << f(N) << "\n";
    }
}