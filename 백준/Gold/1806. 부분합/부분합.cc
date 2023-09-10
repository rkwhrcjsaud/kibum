#include <iostream>

#define MIN(a, b) (a > b ? b : a)
int N, S;
int min;
int arr[100002];

int	compare(int a, int b)
{
	return (a < b);
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cin >> N >> S;
	int i = 1;
	while (i <= N)
	{
		int temp;
		std::cin >> temp;
		arr[i] = arr[i - 1] + temp;
		i++;
	}
	min = N + 1;
	i = 1;
	int j = 1;
	while (j <= N)
	{
		if (j >= i && arr[j] - arr[i - 1] >= S)
		{
			min = MIN(min, j - i + 1);
			i++;
		}
		else
			j++;
	}
	if (min == N + 1)
		std::cout << "0\n";
	else
		std::cout << min << "\n";
}