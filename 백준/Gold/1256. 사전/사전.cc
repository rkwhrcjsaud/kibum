#include <iostream>
#include <queue>
#include <vector>

int N, M, K;
int dp[101][101];

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N >> M >> K;
    for (int i = 0; i <= N; i++)
        dp[i][0] = 1;
    for (int i = 0; i <= M; i++)
        dp[0][i] = 1;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]);
            if (dp[i][j] > 1000000000)
                dp[i][j] = 1000000000;
        }
    }
    std::string str = "";
    if (dp[N][M] < K)
    {
        std::cout << "-1\n";
        return 0;
    }
    while (N > 0 && M > 0)
    {
        if (dp[N - 1][M] >= K)
        {
            str += 'a';
            N--;
        }
        else
        {
            str += 'z';
            K -= dp[N - 1][M];
            M--;
        }
    }
    while (N--)
        str += 'a';
    while (M--)
        str += 'z';
    std::cout << str << '\n';
}