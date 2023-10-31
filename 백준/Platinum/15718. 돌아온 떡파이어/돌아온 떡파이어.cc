#include <iostream>

typedef long long ll;
ll T, N, M;

ll power(ll b, ll p, ll div)
{
	if (p == 0)
		return 1;
	ll temp = power(b, p / 2, div) % div;
	if (p % 2 == 1)
		return (((temp * temp) % div) * b % div);
	return ((temp * temp) % div);
}

ll calc_bc(ll n, ll m, ll div)
{
	if (m == 1)
		return n;
	if (m == 0 || n == m)
		return 1;
	if (n - m == 1)
		return n;
	ll a = 1, b = 1;
	ll i = n;
	while (i >= n - m + 1)
	{
		a *= i;
		a %= div;
		i--;
	}
	i = 1;
	while (i <= m)
	{
		b *= i;
		b %= div;
		i++;
	}
	ll btop = power(b, div - 2, div);
	return ((a % div) * (btop % div) % div);
}

ll calc(ll a, ll b, ll div)
{
	ll arr_N[100] = { 0 };
	ll arr_M[100] = { 0 };
	ll i = 0;
	ll size = 0;
	while (a)
	{
		arr_N[i] = a % div;
		a /= div;
		arr_M[i] = b % div;
		b /= div;
		i++;
	}
	size = i;
	ll ans = 1;
	i = 0;
	while (i < size)
	{
		if (arr_N[i] < arr_M[i])
		{
			ans = 0;
			break ;
		}
		ans *= calc_bc(arr_N[i], arr_M[i], div) % div;
		i++;
	}
	return (ans % div);
}

ll calc_rev(ll n, ll div)
{
	ll a = n, b = div;
	while (b > 0)
	{
		ll tmp = a;
		a = b;
		b = tmp % b;
	}
	if (a != 1)
		return 0;
	ll r0 = n, r1 = div;
	ll s0 = 1, s1 = 0;
	ll t0 = 0, t1 = 1;
	ll temp = 0, q = 0;
	while (r1)
	{
		q = r0 / r1;
		temp = r0;
		r0 = r1;
		r1 = temp - r1 * q;
		temp = s0;
		s0 = s1;
		s1 = temp - s1 * q;
		temp = t0;
		t0 = t1;
		t1 = temp - t1 * q;
	}
	ll ans;
	if (t0 > 1)
		ans = t0;
	else
		ans = t0 + n;
	return ans;
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cin >> T;
	while (T--)
	{
		std::cin >> N >> M;
		if (M - 1 > N || (M == 1 && N != 0))
		{
			std::cout << "0\n";
			continue ;
		}
		ll mod97 = calc(N - 1, M - 2, 97);
		ll mod1031 = calc(N - 1, M - 2, 1031);
		ll mod97_rev = calc_rev(1031, 97);
		ll mod1031_rev = calc_rev(97, 1031);
		ll ans = ((1031 * mod1031_rev * mod97) % 100007 + (97 * mod97_rev * mod1031) % 100007) % 100007;
		std::cout << ans << "\n";
	}
}
