#include <iostream>
#include <vector>
#include <algorithm>

int M, N;
std::vector < std::pair < std::pair < int, int >, int > > v;
int parent[200002];

int compare(std::pair < std::pair < int, int >, int > a, 
	std::pair < std::pair < int, int >, int > b)
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
	while (1)
	{
		std::cin >> M >> N;
		if (M == 0 && N == 0)
			break ;
		int i = 0;
		while (i < N)
		{
			int a, b, c;
			std::cin >> a >> b >> c;
			v.push_back(std::make_pair(std::make_pair(a, b), c));
			i++;
		}
		std::sort(v.begin(), v.end(), compare);
		i = 0;
		while (i <= M)
		{
			parent[i] = i;
			i++;
		}
		i = 0;
		int len = 0;
		int size = v.size();
		while (i < size)
		{
			int root_a = find_root(v[i].first.first);
			int root_b = find_root(v[i].first.second);
			if (root_a != root_b)
				parent[root_b] = root_a;
			else
				len += v[i].second;
			i++;
		}
		std::cout << len << "\n";
		v.clear();
	}
}