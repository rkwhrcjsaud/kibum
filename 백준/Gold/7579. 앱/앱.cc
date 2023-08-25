#include <iostream>

#define MAX(a, b) (a > b ? a : b)

int n, m;
int arr[102][2];
int	dp[10002][102];

int	solve(int max, int i)
{
	int j = 1;
	while (j <= n)
	{
		if (i < arr[j][1])
			dp[i][j] = dp[i][j - 1];
		else
			dp[i][j] = MAX(dp[i][j - 1], dp[i - arr[j][1]][j - 1] + arr[j][0]);
		max = MAX(max, dp[i][j]);
		j++;
	}
	if (max >= m)
		return i;
	else
		return 0;
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cin >> n >> m;
	int i = 1;
	while (i <= n)
		std::cin >> arr[i++][0];
	i = 1;
	while (i <= n)
		std::cin >> arr[i++][1];
	i = 1;
	while (i <= 10000)
	{
		int ans = solve(0, i);
		if (ans)
		{
			std::cout << ans << "\n";
			break ;
		}
		i++;
	}
}