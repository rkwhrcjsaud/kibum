#include <iostream>
#include <cstring>
#define ADD(a, b, c) (a > b ? c : 0);
int m, n;
int arr[502][502];
int dp[502][502];

int	solve(int x, int y)
{
	if (x == n && y == m)
		return 1;
	if (dp[y][x] == -1)
	{
		dp[y][x] = 0;
		if (arr[y + 1][x] != 0 && arr[y + 1][x] < arr[y][x])
			dp[y][x] += solve(x, y + 1);
		if (arr[y][x + 1] != 0 && arr[y][x + 1] < arr[y][x])
			dp[y][x] += solve(x + 1, y);
		if (arr[y][x - 1] != 0 && arr[y][x - 1] < arr[y][x])
			dp[y][x] += solve(x - 1, y);
		if (arr[y - 1][x] != 0 && arr[y - 1][x] < arr[y][x])
			dp[y][x] += solve(x, y - 1);
	}
	return dp[y][x];
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cin >> m >> n;
	int i = 1;
	while (i <= m)
	{
		int j = 1;
		while (j <= n)
			std::cin >> arr[i][j++];
		i++;
	}
	memset(dp, -1, sizeof(dp));
	std::cout << solve(1, 1) << "\n";
}
