#include <iostream>

long long dp[31][31];

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	for (int h = 0; h <= 30; h++)
	{
		for (int w = 0; w <= 30; w++)
		{
			if (h > w)
				continue ;
			if (h == 0)
				dp[w][h] = 1;
			else
				dp[w][h] = dp[w - 1][h] + dp[w][h - 1];
		}
	}
	int n;
	while (1)
	{
		std::cin >> n;
		if (n == 0)
			break ;
		std::cout << dp[n][n] << '\n';
	}
}
