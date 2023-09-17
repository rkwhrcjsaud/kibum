#include <iostream>

typedef long long ll;

ll	check(std::pair <ll, ll> a, std::pair <ll, ll> b, std::pair <ll, ll> c, std::pair <ll ,ll> d)
{
	ll	temp1 = (b.first - a.first) * (c.second - a.second);
	ll	temp2 = (c.first - a.first) * (b.second - a.second);
	ll	temp3 = (b.first - a.first) * (d.second - a.second);
	ll	temp4 = (d.first - a.first) * (b.second - a.second);
	return ((temp1 - temp2 > 0) == (temp3 - temp4 > 0));
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	ll a, b, c, d, e, f, g, h;
	std::cin >> a >> b >> c >> d >> e >> f >> g >> h;
	bool	check1 = check(std::make_pair(a, b), std::make_pair(c, d), std::make_pair(e, f), std::make_pair(g, h));
	bool	check2 = check(std::make_pair(e, f), std::make_pair(g, h), std::make_pair(a, b), std::make_pair(c, d));
	if (check1 == 0 && check2 == 0)
		std::cout << "1\n";
	else
		std::cout << "0\n";
}