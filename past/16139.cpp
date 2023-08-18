#include <iostream>

std::string	str;
int	n;

int main(void)
{
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);
	std::cin >> str >> n;
	int len = str.length();
	int i = 0;
	int	dp[len][26];
	while (i < len)
	{
		int j = 0;
		while (j < 26)
			dp[i][j++] = 0;
		i++;
	}
	dp[0][str[0] - 'a'] = 1;
	i = 1;
	while (i < len)
	{
		int j = 0;
		while (j < 26)
		{
			if (str[i] - 'a' != j)
				dp[i][j] = dp[i - 1][j];
			else
				dp[i][j] = dp[i - 1][j] + 1;
			j++;
		}
		i++;
	}
	i = 0;
	while (i < n)
	{
		char c;
		int a, b;
		std::cin >> c >> a >> b;
		if (a == 0)
			std::cout << dp[b][c - 'a'] << "\n";
		else
			std::cout << dp[b][c - 'a'] - dp[a - 1][c - 'a'] << "\n";
		i++;
	}
}