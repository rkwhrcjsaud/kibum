#include <iostream>

int N;
int dp[1000010];
int arr[1000010];

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cin >> N;
	int max = 0;
	for (int i = 1; i <= N; i++)
	{
		std::cin >> arr[i];
		dp[arr[i]] = dp[arr[i] - 1] + 1;
		if (max < dp[arr[i]])
			max = dp[arr[i]];
	}
	std::cout << N - max << '\n';
}