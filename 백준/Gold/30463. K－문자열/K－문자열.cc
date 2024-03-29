#include <iostream>
#include <vector>
#include <bitset>

int N, K;
long long arr[1025];

int bitcount(int n)
{
    int cnt = 0;
    while (n)
    {
        cnt += n & 1;
        n >>= 1;
    }
    return cnt;
}

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N >> K;
    for (int i = 0; i < N; i++)
    {
        std::string str;
        std::cin >> str;
        int bit = 0;
        for (int j = 0; j < 10; j++)
            bit |= 1 << (str[j] - '0');
        arr[bit]++;
    }
    long long cnt = 0;
    for (int i = 0; i < (1 << 10); i++)
    {
        for (int j = i; j < (1 << 10); j++)
        {
            if (i == j)
            {
                if (bitcount(i) == K)
                    cnt += arr[i] * (arr[i] - 1) / 2;
            }
            else
            {
                if (bitcount(i | j) == K)
                    cnt += arr[i] * arr[j];
            }
        }
    }
    std::cout << cnt << '\n';
}