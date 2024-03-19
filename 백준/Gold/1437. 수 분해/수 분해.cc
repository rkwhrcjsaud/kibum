#include <iostream>

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    int N;
    std::cin >> N;
    int ans = 1;
    if (N <= 4)
    {
        std::cout << N << "\n";
        return 0;
    }
    while (N)
    {
        N -= 3;
        ans *= 3;
        ans %= 10007;
        if (N == 2 || N == 4)
        {
            ans *= N;
            ans %= 10007;
            break ;
        }
    }
    std::cout << ans << "\n";
}
