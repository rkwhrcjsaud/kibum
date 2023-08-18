#include <iostream>

typedef unsigned long long int ull;

int n, m;
ull	mod[1002];
ull ans;

int main(void)
{
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);
	std::cin >> n >> m;
	int i = 1;
	ull sum = 0;
	while (i <= n)
	{
		int temp;
		std::cin >> temp;
		sum += temp;
		mod[sum % m]++;
		i++;
	}
	i = 0;
	while (i < m)
	{
		ans += mod[i] * (mod[i] - 1) / 2;
		i++;
	}
	std::cout << ans + mod[0] << "\n";
}
