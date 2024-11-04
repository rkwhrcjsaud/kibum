#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <map>
#include <set>

using namespace std;

int T, N, W;
vector<vector<int> > board;
vector<vector<int> > dp;

void solve()
{
	for (int i = 2; i <= N; i++)
	{
		int up = board[i][1] + board[i - 1][1] <= W ? 1 : 2;
		int down = board[i][0] + board[i - 1][0] <= W ? 1 : 2;
		int col = board[i][0] + board[i][1] <= W ? 1 : 2;

		dp[i][0] = min(dp[i - 1][0] + col, min(dp[i - 2][0] + up + down, min(dp[i - 1][1] + up + 1, dp[i - 1][2] + down + 1)));
		dp[i][1] = min(dp[i - 1][0] + 1, dp[i - 1][2] + down);
		dp[i][2] = min(dp[i - 1][0] + 1, dp[i - 1][1] + up);
	}
}

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
	cin >> T;
	while (T--)
	{
		cin >> N >> W;
		int ans = 1e9;
		board.resize(N + 1, vector<int>(2, 0));
		dp.resize(N + 1, vector<int>(3, 0));
		for (int i = 1; i <= N; i++)
			cin >> board[i][0];
		for (int i = 1; i <= N; i++)
			cin >> board[i][1];
		int up = board[1][1];
		int down = board[1][0];
		dp[1][0] = (board[1][1] + board[1][0] <= W ? 1 : 2);
		dp[1][1] = dp[1][2] = 1;
		solve();
		ans = min(ans, dp[N][0]);

		if (board[1][1] + board[N][1] <= W)
		{
			dp[1][0] = 2;
			dp[1][1] = dp[1][2] = 1;
			board[1][1] = 1e9;
			solve();
			ans = min(ans, dp[N][1]);
			board[1][1] = up;
		}

		if (board[1][0] + board[N][0] <= W)
		{
			dp[1][0] = 2;
			dp[1][1] = dp[1][2] = 1;
			board[1][0] = 1e9;
			solve();
			ans = min(ans, dp[N][2]);
			board[1][0] = down;
		}

		if (board[1][0] + board[N][0] <= W && board[1][1] + board[N][1] <= W)
		{
			dp[1][0] = 2;
			dp[1][1] = dp[1][2] = 1;
			board[1][0] = board[1][1] = 1e9;
			solve();
			ans = min(ans, dp[N - 1][0]);
			board[1][0] = down;
			board[1][1] = up;
		}

		if (N == 1)
			ans = board[1][0] + board[1][1] <= W ? 1 : 2;
		
		cout << ans << '\n';
		dp.clear();
		board.clear();
	}
}