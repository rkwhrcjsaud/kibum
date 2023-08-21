#include <iostream>
#define MIN(a, b) (a > b ? b : a)
#define max 2147483647
int n;
int arr[502];
int sum[502];
int dp[502][502];

void	solve(int m)
{
	int i = 1;
	while (i <= m)
	{
		int j = 1;
		while (j <= m - i)
		{
			dp[j][i + j] = max;
			int k = j;
			while (k < i + j)
			{
				dp[j][j + i] = MIN(dp[j][j + i], dp[j][k] + dp[k + 1][j + i] + sum[i + j] - sum[j - 1]);
				k++;
			}
			j++;
		}
		i++;
	}
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cin >> n;
	int i = 1;
	while (i++ <= n)
	{
		int m;
		std::cin >> m;
		int j = 1;
		while (j <= m)
		{
			std::cin >> arr[j];
			sum[j] = sum[j - 1] + arr[j];
			j++;
		}
		solve(m);
		std::cout << dp[1][m] << "\n";
		j = 1;
		while (j <= m)
		{
			arr[j] = 0;
			sum[j] = 0;
			int k = j;
			while (k <= m)
				dp[j][k++] = 0;
			j++;
		}
	}
}
