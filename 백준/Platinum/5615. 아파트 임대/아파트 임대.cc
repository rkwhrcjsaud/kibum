#include <iostream>
#include <cmath>

typedef unsigned long long ll;
ll T, N, area, ans;
int arr[13] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 61 };

ll power(ll b, ll p, ll div)
{
	if (p == 0)
		return 1;
	ll temp = power(b, p / 2, div) % div;
	if (p % 2 == 1)
		return (((temp * temp) % div) * b % div);
	return ((temp * temp) % div);
}

bool	test_a(ll a)
{
	ll n = N - 1;
	if (a % N == 0)
		return 1;
	while (n % 2 != 1)
	{
		ll temp = power(a, n, N) % N;
		if (temp == 1 || temp == N - 1)
			return 1;
		n /= 2;
	}
	ll temp = power(a, n, N) % N;
	if (temp == 1 || temp == N - 1)
		return 1;
	return 0;
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cin >> T;
	while (T--)
	{
		std::cin >> area;
		N = area * 2 + 1;
		if (area < 4)
		{
			ans++;
			continue ;
		}
		int i = 0;
		while (i < 13)
		{
			if (!test_a(arr[i]))
				break ;
			i++;
		}
		if (i == 13)
			ans++;
	}
	std::cout << ans << "\n";
}
