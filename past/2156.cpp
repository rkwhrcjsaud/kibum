#include <iostream>

#define MAX(a, b) (a > b ? a : b)

int arr[10002];
int	dp[10002][3];

int main(void)
{
	int n;
	std::cin >> n;
	int i = 1;
	while (i <= n)
		std::cin >> arr[i++];
	dp[1][0] = arr[1];
	dp[1][1] = arr[1];
	dp[1][2] = arr[1];
	dp[2][0] = arr[1] + arr[2];
	dp[2][1] = arr[2];
	dp[2][2] = arr[2];
	dp[3][0] = arr[2] + arr[3];
	dp[3][1] = arr[1] + arr[3];
	dp[3][2] = arr[3];
	i = 4;
	int max = MAX(arr[1], arr[1] + arr[2]);
	while (i <= n)
	{
		dp[i][0] = MAX(dp[i - 1][1], dp[i - 1][2]) + arr[i];
		dp[i][1] = MAX(dp[i - 2][0], MAX(dp[i - 2][1], dp[i - 2][2])) + arr[i];
		dp[i][2] = MAX(dp[i - 3][0], MAX(dp[i - 3][1], dp[i - 3][2])) + arr[i];
		int ret = MAX(dp[i][0], MAX(dp[i][1], dp[i][2]));
		max = MAX(max, ret);
		i++;
	}
	std::cout << max << std::endl;
}