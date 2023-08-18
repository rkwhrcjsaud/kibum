#include <iostream>

int n;
int arr[500][500];

void	dp()
{
	int i = n - 1;
	while (i)
	{
		int j = 0;
		while (j < i)
		{
			arr[i - 1][j] += arr[i][j] > arr[i][j + 1] ? arr[i][j] : arr[i][j + 1];
			j++;
		}
		i--;
	}
}

int main(void)
{
	std::cin >> n;
	int i = 0;
	while (i < n)
	{
		int j = 0;
		while (j <= i)
			std::cin >> arr[i][j++];
		i++;
	}
	dp();
	std::cout << arr[0][0] << "\n";
}