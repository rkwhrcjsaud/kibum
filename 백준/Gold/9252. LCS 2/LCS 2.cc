#include <iostream>
#include <stack>
#define MAX(a, b) (a > b ? a : b)

std::string	str1, str2;
int dp[1002][1002];
std::stack <char> s;

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cin >> str1 >> str2;
	int len1 = str1.length();
	int len2 = str2.length();
	int i = 1;
	while (i <= len1)
	{
		int j = 1;
		while (j <= len2)
		{
			if (str1[i - 1] == str2[j - 1])
				dp[i][j] = dp[i - 1][j - 1] + 1;
			else
				dp[i][j] = MAX(dp[i - 1][j], dp[i][j - 1]);
			j++;
		}
		i++;
	}
	i = dp[len1][len2];
	std::cout << i << "\n";
	while (i > 0)
	{
		while (dp[len1][len2] == i)
		{
			if (str1[len1 - 1] == str2[len2 - 1])
			{
				s.push(str1[len1 - 1]);
				len1--;
				len2--;
			}
			else
			{
				if (dp[len1 - 1][len2] < dp[len1][len2 - 1])
					len2--;
				else
					len1--;
			}
		}
		i--;
	}
	while (!s.empty())
	{
		std::cout << s.top();
		s.pop();
	}
	std::cout << "\n";
}