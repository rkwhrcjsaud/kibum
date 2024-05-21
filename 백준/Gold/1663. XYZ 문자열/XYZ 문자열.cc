#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <sstream>
#include <map>

typedef long long ll;
int T, N;
ll K;
char C;
std::string base[3] = {"X", "YZ", "ZX"};
ll dpCnt[101][3] = {{1, 0, 0}, {0, 1, 1}, {1, 0, 1}};
ll dpLen[101] = {1, 2, 2};

ll getLen(int n)
{
    if (n < 3)
        return base[n].length();
    ll &ret = dpLen[n];
    if (ret)
        return ret;
    ret = getLen(n - 3) + getLen(n - 2);
    for (int i = 0; i < 3; i++)
        dpCnt[n][i] = dpCnt[n - 3][i] + dpCnt[n - 2][i];
    return ret;
}

char find(int n, ll k)
{
    if (n < 3)
        return base[n][k];
    if (k < getLen(n - 3))
        return find(n - 3, k);
    else
        return find(n - 2, k - getLen(n - 3));
}

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> T >> N;
    N--;
    if (T == 1)
        std::cout << getLen(N) << '\n';
    else if (T == 2)
    {
        std::cin >> K;
        std::cout << find(N, K - 1) << '\n';
    }
    else if (T == 3)
    {
        std::cin >> C;
        getLen(N);
        std::cout << dpCnt[N][C - 'X'] << '\n';
    }
}