#include <iostream>

int N;
int bit[1 << 10];

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N;
    for (int i = 0; i < N; i++)
    {
        long long tmp;
        int tmpbit = 0;
        std::cin >> tmp;
        while (tmp)
        {
            tmpbit |= 1 << (tmp % 10);
            tmp /= 10;
        }
        bit[tmpbit]++;
    }
    long long ans = 0;
    for (int i = 0; i < 1 << 10; i++)
    {
        for (int j = i; j < 1 << 10; j++)
        {
            if (i == j)
            {
                if (bit[i] > 1)
                    ans += (long long)bit[i] * (bit[i] - 1) / 2;
            }
            else
            {
                if (bit[i] && bit[j] && (i & j))
                    ans += (long long)bit[i] * bit[j];
            }
        }
    }
    std::cout << ans << '\n';
}
