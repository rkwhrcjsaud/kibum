#include <iostream>

int N, M;
int parent[202];
int rank[202];

int find_root(int x)
{
	if (parent[x] != x)
		return (parent[x] = find_root(parent[x]));
	return (parent[x]);
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
		i++;
	}
	i = 1;
	while (i <= N)
	{
		int j = 1;
		while (j <= N)
		{
			int temp;
			int root_i = find_root(i);
			std::cin >> temp;
			if (temp)
			{
				int root_j = find_root(j);
				if (rank[root_i] >= rank[root_j])
				{
					parent[root_j] = root_i;
					rank[root_i]++;
				}
				else
				{
					parent[root_i] = root_j;
					rank[root_j]++;
				}
			}
			j++;
		}
		i++;
	}
	int root;
	std::cin >> root;
	root = find_root(root);
	i = 2;
	while (i <= M)
	{
		int temp;
		std::cin >> temp;
		temp = find_root(temp);
		if (temp != root)
		{
			std::cout << "NO\n";
			return (0);
		}
		i++;
	}
	std::cout << "YES\n";
}