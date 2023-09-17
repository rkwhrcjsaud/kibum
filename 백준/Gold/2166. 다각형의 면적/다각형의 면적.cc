#include <iostream>
#include <vector>

typedef long long ll;

int n;
std::vector < std::pair < ll, ll > > v;

ll	calc_triangle(std::pair <ll, ll> a, std::pair <ll, ll> b, std::pair <ll, ll> c)
{
	ll	temp1 = (b.first - a.first) * (c.second - a.second);
	ll	temp2 = (c.first - a.first) * (b.second - a.second);
	return (temp1 - temp2);
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cin >> n;
	int i = 0;
	while (i < n)
	{
		ll a, b;
		std::cin >> a >> b;
		v.push_back(std::make_pair(a, b));
		i++;
	}
	i = 0;
	int size = v.size();
	long long area = 0;
	while (i <= size - 3)
	{
		std::pair <ll, ll> b = v[i + 1];
		std::pair <ll, ll> c = v[i + 2];
		area += (long double)calc_triangle(v[0], b, c);
		i++;
	}
	std::cout << llabs(area) / 2 << ".";
	if (area % 2 == 0)
		std::cout << "0\n";
	else
		std::cout << "5\n";
}