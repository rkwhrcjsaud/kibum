#include <iostream>
#include <vector>

typedef unsigned long long LL;
LL A, HA, LA;
int cnt;
LL one = 1, mask = 3;

void getLA()
{
    LA = A ^ mask;
    LA /= one;
    LA *= one;
    LL n = (one >> 1);
    int tmp = cnt;
    while (n && tmp--)
    {
        LA += n;
        n >>= 1;
    }
}

void getHA()
{
    HA = A ^ mask;
    HA /= one;
    HA *= one;
    LL n = 1;
    int tmp = cnt;
    while (n < one && tmp--)
    {
        HA += n;
        n <<= 1;
    }
}

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> A;
    while (1)
    {
        if (HA && LA)
            break ;
        if (one > A)
            break ;
        if ((A & mask) == (one << 1LL))
            getLA();
        if ((A & mask) == one)
            getHA();
        if ((A & one))
            cnt++;
        mask <<= 1LL;
        one <<= 1LL;
    }
    std::cout << LA << " " << HA << "\n";
}