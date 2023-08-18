#include <iostream>

typedef	unsigned long long int ull;

int a, b, c;
int	arr[100];

int main(void)
{
	std::ios_base :: sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cin >> a >> b >> c;
	ull ans = a;

	int i = 0;
	while (b != 1)
	{
		if (b % 2 == 1)
			arr[i] = 1;
		else
			arr[i] = 0;
		i++;
		b = b >> 1;
	}
	int limit = i;
	while (limit--)
	{
		ans = (ans * ans) % c;
		if (arr[limit] == 1)
			ans = (ans * a) % c;
	}
	std::cout << ans % c << "\n";
}
