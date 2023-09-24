#include <iostream>

int N, K, ans;
int dp[1001][501];


int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cin >> N >> K;
	if (N / 2 < K)
	{
		std::cout << "0\n";
		return (0);
	}
	dp[3][1] = 3;
	dp[3][0] = 1;
	dp[2][1] = 2;
	dp[2][0] = 1;
	int i = 4;
	while (i <= N)
	{
		int j = 1;
		dp[i][0] = 1;
		while (j <= K)
		{
			dp[i][j] = (dp[i - 2][j - 1] + dp[i - 1][j]) % 1000000003;
			j++;
		}
		i++;
	}
	std::cout << dp[N][K] << "\n";
}
