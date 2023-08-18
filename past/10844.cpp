#include <iostream>


typedef unsigned long long int ull;
ull arr[101][10];

int main(void)
{
	int n;
	std::cin >> n;
	int i = 1;
	while (i < 10)
		arr[1][i++] = 1;
	i = 2;
	while (i <= n)
	{
		int j = 0;
		while (j < 10)
		{
			if (j == 0)
				arr[i][j] = arr[i - 1][j + 1];
			else if (j == 9)
				arr[i][j] = arr[i - 1][j - 1];
			else
				arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j + 1];
			if (arr[i][j] >= 1000000000)
				arr[i][j] = arr[i][j] % 1000000000;
			j++;
		}
		i++;
	}
	ull ans = 0;
	i = 0;
	while (i < 10)
		ans += arr[n][i++];
	std::cout << ans % 1000000000 << "\n";
}