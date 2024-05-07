#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

int N;
std::string p, s;
int psize, ssize;
int dp[101][101];

int solve(int idx, int sidx)
{
    if (idx == psize && sidx == ssize)
        return 1;
    int &ret = dp[idx][sidx];
    if (ret != -1)
        return ret;
    ret = 0;
    if (p[idx] == '*')
    {
        for (int i = sidx; i <= ssize; i++)
            ret |= solve(idx + 1, i);
    }
    else
    {
        if (p[idx] == s[sidx])
            ret |= solve(idx + 1, sidx + 1);
    }
    return ret;
}

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> p >> N;
    psize = p.size();
    while (N--)
    {
        std::cin >> s;
        ssize = s.size();
        memset(dp, -1, sizeof(dp));
        if (solve(0, 0))
            std::cout << s << '\n';
    }
}