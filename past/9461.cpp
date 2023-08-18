#include <iostream>

unsigned long long int arr[102];

unsigned long long int dp(int m)
{
	arr[1] = 1;
	arr[2] = 1;
	arr[3] = 1;
	arr[4] = 2;
	arr[5] = 2;
	int i = 6;
	while (i <= m)
	{
		arr[i] = arr[i - 1] + arr[i - 5];
		i++;
	}
	return arr[m];
}

int main(void)
{
	int n;
	std::cin >> n;
	while (n--)
	{
		int m;
		std::cin >> m;
		std::cout << dp(m) << "\n";
	}
}