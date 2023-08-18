#include <iostream>

#define MIN(a, b) (a > b ? b : a)

int arr[1000][3];
int temp[1000][3];
int n;
int min;

int calcMin(int a, int b, int c)
{
	return (MIN(MIN(a, b), c));
}

void dp()
{
	temp[0][0] = arr[0][0];
	temp[0][1] = arr[0][1];
	temp[0][2] = arr[0][2];
	int i = 1;
	while (i < n)
	{
		int j = 0;
		while (j < 3)
		{
			temp[i][j] = MIN(temp[i - 1][(j + 1) % 3], temp[i - 1][(j + 2) % 3]) + arr[i][j];
			j++;
		}
		i++;
	}
	min = calcMin(temp[n - 1][0], temp[n - 1][1], temp[n - 1][2]);
}

int main(void)
{
	std::cin >> n;
	int i = 0;
	while (i < n)
	{
		int j = 0;
		while (j < 3)
			std::cin >> arr[i][j++];
		i++;
	}
	dp();
	std::cout << min << "\n";
}