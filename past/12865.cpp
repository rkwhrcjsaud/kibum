#include <iostream>

#define MAX(a, b) (a > b ? a : b)

int n;
int k;
int arr[102][2];
int dp[100002][102];
int max;

int main(void)
{
	std::cin >> n >> k;
	int i = 0;
	while (++i <= n)
		std::cin >> arr[i][0] >> arr[i][1];
	i = 1;
	while (i <= k)
	{
		int j = 1;
		while (j <= n)
		{
			if (i < arr[j][0])
				dp[i][j] = dp[i][j - 1];
			else
				dp[i][j] = MAX(dp[i][j - 1], dp[i - arr[j][0]][j - 1] + arr[j][1]);
			max = MAX(max, dp[i][j]);
			j++;
		}
		i++;
	}
	std::cout << max << std::endl;
}