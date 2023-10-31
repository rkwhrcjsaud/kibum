#include <iostream>

typedef long long ll;
ll N, M, K;
int arr_N[100];
int arr_M[100];
ll ans;

ll power(ll b, ll p)
{
	if (p == 0)
		return 1;
	ll temp = power(b, p / 2) % K;
	if (p % 2 == 1)
		return (((temp * temp) % K) * b % K);
	return ((temp * temp) % K);
}

int calc_bc(int n, int m)
{
	if (m == 1)
		return n;
	if (m == 0 || n == m)
		return 1;
	if (n - m == 1)
		return n;
	ll a = 1, b = 1;
	int i = n;
	while (i >= n - m + 1)
	{
		a *= i;
		a %= K;
		i--;
	}
	i = 1;
	while (i <= m)
	{
		b *= i;
		b %= K;
		i++;
	}
	ll btop = power(b, K - 2);
	return ((a % K) * (btop % K) % K);
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cin >> N >> M >> K;
	int i = 0;
	int size = 0;
	while (N)
	{
		arr_N[i] = N % K;
		N /= K;
		arr_M[i] = M % K;
		M /= K;
		i++;
	}
	size = i;
	ans = 1;
	i = 0;
	while (i < size)
	{
		if (arr_N[i] < arr_M[i])
		{
			ans = 0;
			break ;
		}
		ans *= calc_bc(arr_N[i], arr_M[i]) % K;
		i++;
	}
	std::cout << ans % K << "\n";
}