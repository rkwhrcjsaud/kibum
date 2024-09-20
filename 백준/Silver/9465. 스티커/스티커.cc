#include <iostream>
#include <string>
#include <vector>

using namespace std;

int T, N;

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    cin >> T;
    while (T--)
    {
        cin >> N;
        vector<vector<int> > arr(2, vector<int>(N, 0));
        vector<vector<int> > dp(3, vector<int>(N, 0));
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < N; j++)
                cin >> arr[i][j];
        dp[0][0] = 0;
        dp[1][0] = arr[0][0];
        dp[2][0] = arr[1][0];
        for (int i = 1; i < N; i++)
        {
            dp[0][i] = max(dp[0][i - 1], max(dp[1][i - 1], dp[2][i - 1]));
            dp[1][i] = max(dp[0][i - 1], dp[2][i - 1]) + arr[0][i];
            dp[2][i] = max(dp[0][i - 1], dp[1][i - 1]) + arr[1][i];
        }
        cout << max(dp[0][N - 1], max(dp[1][N - 1], dp[2][N - 1])) << '\n';
    }
}