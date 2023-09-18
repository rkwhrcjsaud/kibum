#include <iostream>

typedef long long ll;

int ccw(std::pair <ll, ll> a, std::pair <ll, ll> b, std::pair <ll, ll> c)
{
	ll temp = a.first * b.second + b.first * c.second + c.first * a.second;
	temp -= b.first * a.second + c.first * b.second + a.first * c.second;
	if (temp > 0)
		return 1;
	else if (temp == 0)
		return 0;
	return (-1);
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	ll a, b, c, d, e, f, g, h;
	std::cin >> a >> b >> c >> d >> e >> f >> g >> h;
	std::pair <ll, ll> A = std::make_pair(a, b);
	std::pair <ll, ll> B = std::make_pair(c, d);
	std::pair <ll, ll> C = std::make_pair(e, f);
	std::pair <ll, ll> D = std::make_pair(g, h);
	int temp1 = ccw(A, B, C) * ccw(A, B, D);
	int temp2 = ccw(C, D, A) * ccw(C, D, B);
	if (temp1 == 0 && temp2 == 0)
	{
		if (A > B)
			swap(A, B);
		if (C > D)
			swap(C, D);
		if (A <= D && B >= C)
		{
			std::cout << "1";
			return 0;
		}
		std::cout << "0";
		return (0);
	}
	else
	{
		if (temp1 <= 0 && temp2 <= 0)
		{
			std::cout << "1";
			return 0;
		}
		std::cout << "0";
		return 0;
	}
}