#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

int N, M, K;
std::string str;
char board[101][101];
int dp[101][101][81];

int solve(int y, int x, int idx)
{
    if (idx == str.size() - 1)
        return 1;
    if (dp[y][x][idx] != -1)
        return dp[y][x][idx];
    int ret = 0;
    for (int i = 1; i <= K; i++)
    {
        if (y + i < N && board[y + i][x] == str[idx + 1])
            ret += solve(y + i, x, idx + 1);
        if (y - i >= 0 && board[y - i][x] == str[idx + 1])
            ret += solve(y - i, x, idx + 1);
        if (x + i < M && board[y][x + i] == str[idx + 1])
            ret += solve(y, x + i, idx + 1);
        if (x - i >= 0 && board[y][x - i] == str[idx + 1])
            ret += solve(y, x - i, idx + 1);
    }
    return dp[y][x][idx] = ret;
}

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N >> M >> K;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            std::cin >> board[i][j];
    std::fill(&dp[0][0][0], &dp[100][100][81], -1);
    std::cin >> str;
    int ans = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (board[i][j] != str[0])
                continue ;
            ans += solve(i, j, 0);
        }
    }
    std::cout << ans << '\n';
}