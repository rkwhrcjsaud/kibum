#include <iostream>

unsigned long long N, K;

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N >> K;
    unsigned long long ans = 0;
    for (int i = 0, j = 0; i < 65; i++)
    {
        if (!(N & (1LL << i)))
        {
            if (K & (1LL << j))
                ans |= (1LL << i);
            j++;
        }
    }
    std::cout << ans << '\n';
}
