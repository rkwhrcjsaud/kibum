#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <sstream>
#include <map>

int N, M, C;
int W[17][17];
int A[1001];
int B[1001];
typedef long long ll;
ll dp[1001][1001];

ll solve(int a, int b)
{
    if (a == N + 1 || b == M + 1)
        return 0;
    ll &ret = dp[a][b];
    if (ret != -1)
        return ret;
    ret = 0;
    ret = std::max(ret, solve(a + 1, b + 1) + W[A[a]][B[b]]);
    ret = std::max(ret, solve(a + 1, b));
    ret = std::max(ret, solve(a, b + 1));
    return ret;

}

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N >> M >> C;
    for (int i = 1; i <= C; i++)
        for (int j = 1; j <= C; j++)
            std::cin >> W[i][j];
    for (int i = 1; i <= N; i++)
        std::cin >> A[i];
    for (int i = 1; i <= M; i++)
        std::cin >> B[i];
    memset(dp, -1, sizeof(dp));
    std::cout << solve(1, 1) << '\n';
}