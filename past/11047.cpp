#include <iostream>

int n, k;
int	arr[12];
int cnt;

int main(void)
{
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);
	std::cin >> n >> k;
	int i = 1;
	while (i <= n)
		std::cin >> arr[i++];
	i = n;
	while (i > 0)
	{
		while (k >= arr[i])
		{
			k -= arr[i];
			cnt++;
		}
		i--;
	}
	std::cout << cnt << "\n";
}