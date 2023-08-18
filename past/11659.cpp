#include <iostream>

int n;
int m;
int	arr[100002];

int main(void)
{
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);
	std::cin >> n >> m;
	int i = 1;
	while (i <= n)
	{
		std::cin >> arr[i];
		arr[i] += arr[i - 1];
		i++;
	}
	i = 0;
	while (i < m)
	{
		int a, b;
		std::cin >> a >> b;
		std::cout << arr[b] - arr[a - 1] << "\n";
		i++;
	}
}