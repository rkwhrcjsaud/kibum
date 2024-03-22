#include <iostream>
#include <vector>

int N;
std::vector<unsigned int> ip;

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N;
    for (int i = 0; i < N; i++)
    {
        unsigned int n1, n2, n3, n4;
        char c;
        std::cin >> n1 >> c >> n2 >> c >> n3 >> c >> n4;
        unsigned int bit = 0;
        bit |= n4;
        bit |= (n3 << 8);
        bit |= (n2 << 16);
        bit |= (n1 << 24);
        ip.push_back(bit);
    }
    for (unsigned int i = 0; i <= 32; i++)
    {
        bool flag = false;
        unsigned int mask = ((1LL << 32) - 1) ^ ((1LL << i) - 1);
        unsigned int bit = mask & ip[0];
        for (int j = 1; j < N; j++)
        {
            unsigned int tmp = mask & ip[j];
            if (tmp != bit)
            {
                flag = true;
                break ;
            }
        }
        if (!flag)
        {
            std::cout << (bit >> 24) << '.'
                << ((bit >> 16) & 0xff) << '.'
                << ((bit >> 8) & 0xff) << '.'
                << (bit & 0xff) << '\n';
            std::cout << (mask >> 24) << '.'
                << ((mask >> 16) & 0xff) << '.'
                << ((mask >> 8) & 0xff) << '.'
                << (mask & 0xff) << '\n';
            return 0;
        }
    }
}
