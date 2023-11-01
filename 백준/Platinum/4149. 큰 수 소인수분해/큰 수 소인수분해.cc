#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <cmath>

#define MAX(a, b) (a > b ? a : b)
#define MIN(a, b) (a < b ? a : b)
typedef unsigned long long ll;
typedef __int128_t i128;
ll N;
i128 arr[7] = { 2, 325, 9375, 28178, 450775, 9780504, 1795265022 };
std::vector <ll> pf;

ll mul(ll x, ll y, ll div)
{
	return ((i128)x * y) % div;
}

ll power(ll b, ll p, ll div)
{
	ll ret = 1, piv = b % div;
	while (p)
	{
		if (p & 1)
			ret = mul(ret, piv, div);
		piv = mul(piv, piv, div);
		p >>= 1;
	}
	return ret;
}

bool	test_a(ll a, ll n)
{
	ll nn = n - 1;
	if (a % n == 0)
		return 1;
	while (1)
	{
		ll temp = power(a, nn, n);
		if (temp == n - 1)
			return 1;
		if (nn & 1)
			return (temp == 1 || temp == n - 1);
		nn >>= 1;
	}
	return 1;
}

bool is_prime(ll n)
{
	int i = 0;
	while (i < 7)
	{
		if (!test_a(arr[i], n))
			break ;
		i++;
	}
	if (i == 7)
		return 1;
	return 0;
}

ll gcd(ll a, ll b)
{
	while (1)
	{
		ll r = a % b;
		if (r == 0)
			return b;
		a = b;
		b = r;
	}
	return 1;
}

ll f(ll x, ll n, ll a)
{
	return ((mul(x, x, n) + a) % n);
}

void	fn(ll n)
{
	if (n == 1)
		return ;
	if (n % 2 == 0)
	{
		pf.push_back(2);
		fn(n >> 1);
		return ;
	}
	if (is_prime(n))
	{
		pf.push_back(n);
		return ;
	}
	ll g = 1, j, k, a;
	j = k = rand() % (n - 2) + 2;
	a = j % 20 + 1;
	while (g == 1)
	{
		if (g == n)
		{
			j = k = rand() % (n - 2) + 2;
			a = j % 20 + 1;
		}
		j = f(j, n, a);
		k = f(f(k, n, a), n, a);
		g = gcd(MAX(j, k) - MIN(j, k), n);
	}
	fn(g);
	fn(n / g);
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cin >> N;
	fn(N);
	std::sort(pf.begin(), pf.end());
	int i = 0;
	while (i < pf.size())
	{
		std::cout << pf[i] << "\n";
		i++;
	}
}
