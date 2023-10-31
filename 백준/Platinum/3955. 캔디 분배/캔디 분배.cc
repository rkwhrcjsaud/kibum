#include <iostream>

typedef long long ll;
ll T, K, C;

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cin >> T;
	while (T--)
	{
		std::cin >> K >> C;
		ll a = K, b = C;
		while (b > 0)
		{
			int tmp = a;
			a = b;
			b = tmp % b;
		}
		if (a != 1)
		{
			std::cout << "IMPOSSIBLE\n";
			continue ;
		}
		ll r0 = K, r1 = C;
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
			ans = t0 + K;
		if (ans > 1000000000)
			std::cout << "IMPOSSIBLE\n";
		else
			std::cout << ans << "\n";
	}
}
