#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

int N, L, R;
std::string s1, s2;
char c[2];
int arr[10001];
int dp[10001][3];

int solve(int idx1, int idx2, int k)
{
    if (idx1 == N && k == 2)
        return 1;
    int &ret = dp[idx1][k];
    if (ret != -1)
        return ret;
    ret = 0;
    if (idx1 == L || idx1 == R)
        return ret |= solve(idx1 + 1, idx2, k);
    if (s1[idx1] == s2[idx2])
        ret |= solve(idx1 + 1, idx2 + 1, k);
    else if (k == 2)
        return ret;
    if (s2[idx2] == c[k])
        ret |= solve(idx1, idx2 + 1, k + 1);
    return ret;
}

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N >> s1 >> s2 >> L >> R;
    c[0] = s1[L];
    c[1] = s1[R];
    memset(dp, -1, sizeof(dp));
    std::cout << (solve(0, 0, 0) ? "YES" : "NO") << '\n';
}
