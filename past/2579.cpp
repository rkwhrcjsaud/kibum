#include <iostream>

#define MAX(a, b) (a > b ? a : b)

int n;
int arr[300];
int	dp[300][2];

int main(void)
{
	std::cin >> n;
	int i = 0;
	while (i < n)
		std::cin >> arr[i++];
	dp[0][0] = arr[0];
	dp[0][1] = arr[0];
	dp[1][0] = arr[1] + arr[0];
	dp[1][1] = arr[1];
	i = 2;
	while (i < n)
	{
		dp[i][0] = dp[i - 1][1] + arr[i];
		dp[i][1] = MAX(dp[i - 2][0], dp[i - 2][1]) + arr[i];
		i++;
	}
	std::cout << MAX(dp[n - 1][0], dp[n - 1][1]) << "\n";
}