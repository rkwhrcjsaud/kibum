#include <iostream>

int arr[1001];
int dp[1001];
int n;
int max;

int main(void)
{
	std::cin >> n;
	int i = 1;
	while (i <= n)
		std::cin >> arr[i++];
	i = 1;
	while (i <= n)
	{
		int j = 0;
		while (j < i)
		{
			if (arr[i] > arr[j] && dp[i] <= dp[j])
			{
				dp[i] = dp[j] + 1;
				if (max < dp[i])
					max = dp[i];
			}
			j++;
		}
		i++;
	}
	std::cout << max << std::endl;
}