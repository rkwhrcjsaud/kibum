#include <iostream>

int arr[1002];
int dpup[1002];
int dpdown[1002];
int n;
int max;

int main(void)
{
	std::cin >> n;
	int i = 1;
	while (i <= n)
		std::cin >> arr[i++];
	i = 1;
	while (i <= n)
	{
		int j = 0;
		while (j < i)
		{
			if (arr[i] > arr[j] && dpup[i] <= dpup[j])
				dpup[i] = dpup[j] + 1;
			j++;
		}
		i++;
	}
	i = n;
	while (i > 0)
	{
		int j = n + 1;
		while (j > i)
		{
			if (arr[i] > arr[j] && dpdown[i] <= dpdown[j])
				dpdown[i] = dpdown[j] + 1;
			j--;
		}
		i--;
	}
	i = 1;
	while (i <= n)
	{
		if (max < dpdown[i] + dpup[i] - 1)
			max = dpdown[i] + dpup[i] - 1;
		i++;
	}
	std::cout << max << std::endl;
}