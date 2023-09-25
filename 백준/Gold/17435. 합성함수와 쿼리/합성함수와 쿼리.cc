#include <iostream>

int m, Q;
int dp[20][200001];

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cin >> m;
	int i = 1;
	while (i <= m)
		std::cin >> dp[0][i++];
	i = 1;
	while (i < 20)
	{
		int j = 1;
		while (j <= m)
		{
			dp[i][j] = dp[i - 1][dp[i - 1][j]];
			j++;
		}
		i++;
	}
	std::cin >> Q;
	i = 0;
	while (i < Q)
	{
		int n, x;
		std::cin >> n >> x;
		int j = 0;
		while (n)
		{
			if (n & (1 << j))
			{
				x = dp[j][x];
				n -= 1 << j;
				j = 0;
			}
			else
				j++;
		}
		std::cout << x << "\n";
		i++;
	}
}