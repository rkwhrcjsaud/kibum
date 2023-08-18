#include <iostream>

#define MIN(a, b) (a > b ? b : a)

int arr[1000001];

int main(void)
{
	int n;
	std::cin >> n;
	arr[1] = 0;
	arr[2] = 1;
	arr[3] = 1;
	int i = 4;
	while (i <= n)
	{
		arr[i] = arr[i - 1];
		if (i % 2 == 0)
			arr[i] = MIN(arr[i], arr[i / 2]);
		if (i % 3 == 0)
			arr[i] = MIN(arr[i], arr[i / 3]);
		arr[i]++;
		i++;
	}
	std::cout << arr[n] << "\n";
}