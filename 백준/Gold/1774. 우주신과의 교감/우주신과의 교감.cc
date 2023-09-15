#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

int N, M;
int parent[1002];
std::vector < std::pair < int, int > > v;
std::vector < std::pair < std::pair < int, int >, long double > > v2;

long double	calc_distance(long long x, long long y, long long xx, long long yy)
{
	return (sqrt((x - xx) * (x - xx) + (y - yy) * (y - yy)));
}

int	find_root(int x)
{
	if (x != parent[x])
		return (parent[x] = find_root(parent[x]));
	return (parent[x]);
}

int compare(std::pair < std::pair < int, int >, double > a,
	std::pair < std::pair < int, int >, double > b)
{
	return (a.second < b.second);
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cin >> N >> M;
	int i = 1;
	while (i <= N)
	{
		parent[i] = i;
		int x, y;
		std::cin >> x >> y;
		int j = 1;
		int size = v.size();
		while (j <= size)
		{
			int xx = v[j - 1].first;
			int yy = v[j - 1].second;
			long double distance = calc_distance(x, y, xx, yy);
			v2.push_back(std::make_pair(std::make_pair(i, j), distance));
			j++;
		}
		v.push_back(std::make_pair(x, y));
		i++;
	}
	i = 0;
	while (i < M)
	{
		int a, b;
		std::cin >> a >> b;
		int root_a = find_root(a);
		int root_b = find_root(b);
		if (root_a != root_b)
			parent[root_b] = root_a;
		i++;
	}
	std::sort(v2.begin(), v2.end(), compare);
	i = 0;
	long double len = 0;
	int size = v2.size();
	while (i < size)
	{
		int root_a = find_root(v2[i].first.first);
		int root_b = find_root(v2[i].first.second);
		if (root_a != root_b)
		{
			parent[root_b] = root_a;
			len += v2[i].second;
		}
		i++;
	}
	std::cout << std::fixed;
	std::cout.precision(2);
	std::cout << len << "\n";
}