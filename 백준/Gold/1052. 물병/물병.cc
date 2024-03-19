#include <iostream>

int N, K;
int cnt;

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N >> K;
    int tmp = N;
    while (tmp)
    {
        if (tmp & 1)
            cnt++;
        tmp >>= 1;
    }
    if (cnt <= K)
    {
        std::cout << 0 << "\n";
        return 0;
    }
    int i = 31;
    while (i >= 0)
    {
        if ((N >> i) & 1)
        {
            K--;
            N -= (1 << i);
            if (K == 0)
                break ;
        }
        i--;
    }
    N = (1 << i) - N;
    i = 31;
    std::cout << N << '\n';
}