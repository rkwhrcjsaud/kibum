#include <iostream>

#define DIV	1000000007
typedef unsigned long long int ull;
int n, k;

ull power(ull b, ull p)
{
	if (p == 0)
		return 1;
	ull temp = power(b, p / 2) % DIV;
	if (p % 2 == 1)
		return (((temp * temp) % DIV) * b % DIV);
	return ((temp * temp) % DIV);
}

int main(void)
{
	std::ios_base :: sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cin >> n >> k;
	
	if (k == 1)
	{
		std::cout << n << "\n";
		return 0;
	}
	else if (k == 0 || n == k)
	{
		std::cout << 1 << "\n";
		return 0;
	}
	else if (n - k == 1)
	{
		std::cout << n << "\n";
		return 0;
	}
	ull a = 1, b = 1;
	int i = n;
	while (i >= n - k + 1) //(n - k)!
	{
		a = (a * i) % DIV;
		i--;
	}
	i = 1;
	while (i <= k) // k!
	{
		b = (b * i) % DIV;
		i++;
	}
	ull btop = power(b, DIV - 2);
	ull ans = (a % DIV) * (btop % DIV) % DIV;
	std::cout << ans << "\n";
}

