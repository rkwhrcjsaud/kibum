#include <iostream>
#define LIMIT 2147483647
#define MIN(a, b) (a > b ? b : a)
int n;
int	arr[502][2];
int dp[502][502];

void	solve()
{
	int i = 1;
	while (i <= n)
	{
		int j = 1;
		while (j <= n - i)
		{
			int k = j;
			dp[j][i + j] = LIMIT;
			while (k < j + i)
			{
				dp[j][i + j]
					= MIN(dp[j][i + j],
						dp[j][k] + dp[k + 1][i + j]
						+ arr[j][0] * arr[k][1] * arr[i + j][1]);
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
	while (i <= n)
	{
		std::cin >> arr[i][0] >> arr[i][1];
		i++;
	}
	solve();
	std::cout << dp[1][n] << "\n";
}
