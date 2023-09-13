#include <iostream>
#include <vector>
#include <algorithm>

int V, E;
int parent[10002];
std::vector < std::pair < std::pair<int, int>, int > > v;

int compare(std::pair < std::pair<int, int>, int > a,
	std::pair < std::pair<int, int>, int > b)
{
	return (a.second < b.second);
}

int find_root(int x)
{
	if (x != parent[x])
		return (parent[x] = find_root(parent[x]));
	return (parent[x]);
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cin >> V >> E;
	int i = 0;
	while (i <= V)
	{
		parent[i] = i;
		i++;
	}
	i = 0;
	while (i < E)
	{
		int a, b, c;
		std::cin >> a >> b >> c;
		v.push_back(std::make_pair(std::make_pair(a, b), c));
		i++;
	}
	std::sort(v.begin(), v.end(), compare);
	i = 0;
	long long len = 0;
	while (i < E)
	{
		int root1 = find_root(v[i].first.first);
		int root2 = find_root(v[i].first.second);
		if (root1 != root2)
		{
			len += v[i].second;
			parent[root2] = root1;
		}
		i++;
	}
	std::cout << len << "\n";
}