#include <iostream>

#define MAX(a, b) (a > b ? a : b)

int	arr[1002][1002];
int max;

int main(void)
{
	std::string	str[2];
	std::cin >> str[0] >> str[1];
	int n = str[0].length();
	int m = str[1].length();
	int i = 0;
	max = 0;
	while (i < n)
	{
		int j = 0;
		while (j < m)
		{
			if (str[0][i] == str[1][j])
			{
				if (i == 0 || j == 0)
					arr[i][j] = 1;
				else
					arr[i][j] = arr[i - 1][j - 1] + 1;
			}
			else
			{
				if (i == 0 && j == 0)
					arr[i][j] = 0;
				else if (i == 0)
					arr[i][j] = arr[i][j - 1];
				else if (j == 0)
					arr[i][j] = arr[i - 1][j];
				else
					arr[i][j] = MAX(arr[i - 1][j], arr[i][j - 1]);
			}
			max = MAX(max, arr[i][j]);
			j++;
		}
		i++;
	}
	std::cout << max << std::endl;
}