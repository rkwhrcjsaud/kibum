#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#include <map>

using namespace std;



int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    int N;
    cin >> N;
    vector<vector<int> > board(N, vector<int>(N, 0));
    vector<vector<int> > dp(N, vector<int>(N, 0));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> board[i][j];
            if (board[i][j] == 1)
                dp[i][j] = 1;
            else
                dp[i][j] = 1e9;
        }
    }
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            for (int k = 0; k < N; k++)
                dp[j][k] = min(dp[j][k], dp[j][i] + dp[i][k]);
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (dp[i][j] == 1e9)
                cout << 0 << ' ';
            else
                cout << 1 << ' ';
        }
        cout << '\n';
    }
}