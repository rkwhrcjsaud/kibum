#include <iostream>

#define MIN(a, b) (a < b ? a : b)
std::string str;
int		dp[2501];
bool	is_p[2501][2501];

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cin >> str;
	int i = 0;
	int len = str.length();
	while (i < len)
	{
		is_p[i][i] = 1;
		dp[i] = 2501;
		if (str[i] == str[i + 1])
			is_p[i][i + 1] = 1;
		i++;
	}
	int k = 2;
	while (k < len)
	{
		i = 0;
		while (i < len - k)
		{
			int j = i + k;
			if (str[i] == str[j] && is_p[i + 1][j - 1])
				is_p[i][j] = 1;
			i++;
		}
		k++;
	}
	i = 0;
	while (i < len)
	{
		int j = 0;
		while (j <= i)
		{
			if (is_p[j][i])
				dp[i] = MIN(dp[i], dp[j - 1] + 1);
			else
				dp[i] = MIN(dp[i], dp[i - 1] + 1);
			j++;
		}
		i++;
	}
	std::cout << dp[len - 1] << "\n";
}