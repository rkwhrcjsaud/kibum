#include <iostream>
#include <map>

int N;
std::map<long long, int> m1;
std::map<long long, int> m2;

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N;
    long long ans = 0;
    long long bit = 0;
    m2[0] = 1;
    for (long long i = 0; i < N; i++)
    {
        char c;
        std::cin >> c;
        if (std::islower(c))
            bit ^= 1LL << (c - 'a');
        else
            bit ^= 1LL << (c - 'A' + 26);
        if (i % 2 == 0)
        {
            if (m1.find(bit) != m1.end())
                ans += m1[bit];
            for (long long j = 0; j < 52; j++)
            {
                long long odd = bit ^ (1LL << j);
                if (m2.find(odd) != m2.end())
                    ans += m2[odd];
            }
        }
        else
        {
            if (m2.find(bit) != m2.end())
                ans += m2[bit];
            for (long long j = 0; j < 52; j++)
            {
                long long odd = bit ^ (1LL << j);
                if (m1.find(odd) != m1.end())
                    ans += m1[odd];
            }
        }
        if (i % 2 == 0)
            m1[bit]++;
        else
            m2[bit]++;
    }
    std::cout << ans << '\n';
}