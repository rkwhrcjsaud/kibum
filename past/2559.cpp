#include <iostream>

int n, k;
int arr[100002];
int max;

int main(void)
{
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);
	std::cin >> n >> k;
	int i = 1;
	while (i <= n)
	{
		std::cin >> arr[i];
		arr[i] += arr[i - 1];
		i++;
	}
	i = 0;
	max = -100000000;
	while (i <= n - k)
	{
		max = arr[i + k] - arr[i] > max ? arr[i + k] - arr[i] : max;
		i++;
	}
	std::cout << max << "\n";
}