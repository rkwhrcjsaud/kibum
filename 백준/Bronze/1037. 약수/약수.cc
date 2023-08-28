#include <iostream>

#define MIN(a, b) (a > b ? b : a)
#define MAX(a, b) (a > b ? a : b)

int n, min, max;
int arr[52];

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cin >> n;
	int i = 0;
	min = 2147483647;
	max = 0;
	while (i < n)
	{
		std::cin >> arr[i];
		min = MIN(min, arr[i]);
		max = MAX(max, arr[i]);
		i++;
	}
	std::cout << min * max << "\n";
}