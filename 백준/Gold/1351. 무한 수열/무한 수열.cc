#include <iostream>
#include <queue>
#include <vector>

long long N, P, Q;
const long long M = 10000000;
long long dp[M];

long long bfs(long long n)
{
    if (n == 0)
        return 1;
    if (n >= M)
        return bfs(n / P) + bfs(n / Q);
    if (dp[n] != 0)
        return dp[n];
    return dp[n] = bfs(n / P) + bfs(n / Q);
}

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N >> P >> Q;
    std::cout << bfs(N) << '\n';
}