#include <iostream>

int n, m;
int parent[1000002];
int rank[1000002];

int find_root(int x)
{
	if (parent[x] != x)
		return (parent[x] = find_root(parent[x]));
	return parent[x];
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cin >> n >> m;
	int i = 0;
	while (i <= n)
	{
		parent[i] = i;
		i++;
	}
	i = 0;
	while (i < m)
	{
		int temp, a, b;
		std::cin >> temp >> a >> b;
		int root_a = find_root(a);
		int root_b = find_root(b);
		if (!temp)
		{
			if (a == b)
				;
			else if (rank[root_a] >= rank[root_b])
			{
				parent[root_b] = root_a;
				rank[root_a]++;
			}
			else
			{
				parent[root_a] = root_b;
				rank[root_b]++;
			}
		}
		else
		{
			if (root_a == root_b)
				std::cout << "YES\n";
			else
				std::cout << "NO\n";
		}
		i++;
	}
}