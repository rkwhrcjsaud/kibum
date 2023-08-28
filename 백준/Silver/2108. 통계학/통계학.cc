#include <iostream>
#include <algorithm>
#include <cmath>

#define MAX(a, b) (a > b ? a : b)
#define MIN(a, b) (a > b ? b : a)

int n, min, max, sum, max_bin;
int arr[500002];
int	bin[10000];

int	compare(int a, int b)
{
	return (a < b);
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cin >> n;
	int i = 0;
	min = 2147483647;
	max = -2147483648;
	while (i < n)
	{
		std::cin >> arr[i];
		sum += arr[i];
		min = MIN(min, arr[i]);
		max = MAX(max, arr[i]);
		bin[arr[i] + 5000]++;
		max_bin = MAX(max_bin, bin[arr[i] + 5000]);
		i++;
	}
	std::sort(arr, arr + n, compare);
	std::cout << floor((double)sum / n + 0.5) << "\n";
	std::cout << arr[n / 2] << "\n";
	int range = max - min;
	i = 0;
	int k = 0;
	while (i < 10000)
	{
		if (bin[i] == max_bin)
			arr[k++] = i;
		i++;
	}
	if (k == 1)
		std::cout << arr[0] - 5000 << "\n";
	else
	{
		std::sort(arr, arr + k, compare);
		std::cout << arr[1] - 5000 << "\n";
	}
	std::cout << range << "\n";
}