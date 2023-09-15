#include <iostream>
#include <vector>
#include <algorithm>

int N;
std::vector < std::pair < int, int > > v;

int compare(std::pair < int, int > a, std::pair < int, int > b)
{
	return (a.second > b.second);
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cin >> N;
	int i = 0;
	while (i < N)
	{
		int a, b;
		std::cin >> a >> b;
		v.push_back(std::make_pair(a, b));
		i++;
	}
	std::sort(v.begin(), v.end(), compare);
	int d = v[0].second;
	d -= v[0].first;
	i = 1;
	int size = v.size();
	while (i < size)
	{
		if (d > v[i].second)
			d = v[i].second;
		d -= v[i].first;
		i++;
	}
	std::cout << d << "\n";
}