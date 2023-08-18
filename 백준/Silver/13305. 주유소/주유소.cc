#include <iostream>

typedef	unsigned long long int	ull;
int	n;
int	distance[100002];
int price[100002];

int main(void)
{
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);
	std::cin >> n;
	int i = 0;
	while (i < n - 1)
		std::cin >> distance[i++];
	i = 0;
	while (i < n)
		std::cin >> price[i++];
	i = 1;
	int p = price[0];
	ull ans = distance[0] * p;
	while (i < n - 1)
	{
		int temp = 0;
		while (i < n - 1 && p <= price[i])
			temp += distance[i++];
		ans += temp * p;
		p = price[i];
	}
	std::cout << ans << "\n";
}