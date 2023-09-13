#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

int V;
std::vector < std::pair <float, float> > v;
std::vector < std::pair < std::pair < int, int >, float > > v2;
int parent[102];

float	calc_distance(float x, float y, float xx, float yy)
{
	return (sqrtf((x - xx) * (x - xx) + (y - yy) * (y - yy)));
}

int compare(std::pair < std::pair < int, int >, float > a,
	std::pair < std::pair < int, int >, float > b)
{
	return (a.second < b.second);
}

int	find_root(int x)
{
	if (x != parent[x])
		return (parent[x] = find_root(parent[x]));
	return (parent[x]);
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cin >> V;
	int i = 0;
	while (i < V)
	{
		float x, y;
		std::cin >> x >> y;
		int j = 0;
		int size = v.size();
		while (j < size)
		{
			float xx = v[j].first;
			float yy = v[j].second;
			float distance = calc_distance(x, y, xx, yy);
			v2.push_back(std::make_pair(std::make_pair(i, j), distance));
			j++;
		}
		v.push_back(std::make_pair(x, y));
		i++;
	}
	i = 0;
	while (i <= V)
	{
		parent[i] = i;
		i++;
	}
	std::sort(v2.begin(), v2.end(), compare);
	i = 0;
	float len = 0;
	int size = v2.size();
	while (i < size)
	{
		int root1 = find_root(v2[i].first.first);
		int root2 = find_root(v2[i].first.second);
		if (root1 != root2)
		{
			len += v2[i].second;
			parent[root2] = root1;
		}
		i++;
	}
	std::cout << len << "\n";
}