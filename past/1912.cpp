#include <iostream>

int n;
int max;
int arr[100001];
int temp[100001];

void	dp()
{
	int i = 1;
	temp[0] = arr[0];
	max = temp[0];
	while (i < n)
	{
		if (temp[i - 1] + arr[i] > arr[i])
			temp[i] = temp[i - 1] + arr[i];
		else
			temp[i] = arr[i];
		if (max < temp[i])
			max = temp[i];
		i++;
	}
}

int main(void)
{
	int i = 0;
	std::cin >> n;
	while (i < n)
	{
		std::cin >> arr[i];
		i++;
	}
	dp();
	std::cout << max << std::endl;
}