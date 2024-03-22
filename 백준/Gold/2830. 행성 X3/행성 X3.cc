#include <iostream>

long long N;
long long bit[22];

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N;
    long long ans = 0;
    for (int i = 0; i < N; i++)
    {
        int tmp;
        std::cin >> tmp;
        for (int j = 0; j < 22; j++)
        {
            if (tmp & (1 << j))
                bit[j]++;
        }
    }
    for (int i = 0; i < 22; i++)
        ans += (1LL << i) * (bit[i] * (N - bit[i]));
    std::cout << ans << '\n';
}
