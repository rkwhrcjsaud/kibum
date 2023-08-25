#include <iostream>

int n, k, cnt;
int arr[102];
int	dp[10002];

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cin >> n >> k;
	int i = 0;
	while (i < n)
		std::cin >> arr[i++];
	i = 0;
	dp[0] = 1;
	while (i < n)
	{
		int j = arr[i];
		while (j <= k)
		{
			dp[j] = dp[j] + dp[j - arr[i]];
			j++;
		}
		i++;
	}
	std::cout << dp[k] << "\n";
}
