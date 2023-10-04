#include <iostream>
#include <vector>
#include <algorithm>

typedef long long ll;
int N;
std::vector <std::pair <ll, ll> > v;

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cin >> N;
	int i = 0;
	while (i < N)
	{
		ll a, b;
		std::cin >> a >> b;
		v.push_back(std::make_pair(a, b));
		i++;
	}
	std::sort(v.begin(), v.end());
	i = 0;
	int size = v.size();
	ll ans = 0;
	ll s = -1000000001, e = -1000000001;
	while (i < size)
	{
		if (e < v[i].first && e < v[i].second)
		{
			ans += e - s;
			s = v[i].first;
			e = v[i].second;
		}
		else if (v[i].first <= e && v[i].second > e)
			e = v[i].second;
		i++;
	}
	ans += e - s;
	std::cout << ans << "\n";
}