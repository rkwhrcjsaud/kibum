#include <iostream>
#include <vector>
#include <cstring>

int T;
int parent[10001];
std::vector <int> v[10001];

int	find_root(int x)
{
	if (x != parent[x])
		return (parent[x] = find_root(parent[x]));
	return (parent[x]);
}

int dfs(int root, int node1, int node2)
{
	int cnt = 0;
	if (root == node1)
		cnt = 1;
	if (root == node2)
		cnt = 1;
	std::vector <int> vv = v[root];
	int i = 0;
	int size = vv.size();
	while (i < size)
	{
		cnt += dfs(vv[i], node1, node2);
		if (cnt == 2)
		{
			std::cout << root << "\n";
			return 0;
		}
		i++;
	}
	return cnt;
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cin >> T;
	while (T--)
	{
		int N;
		std::cin >> N;
		std::memset(v, 0, sizeof(v));
		std::memset(parent, 0, sizeof(parent));
		int i = 1;
		while (i <= N)
		{
			parent[i] = i;
			i++;
		}
		i = 1;
		while (i < N)
		{
			int a, b;
			std::cin >> a >> b;
			v[a].push_back(b);
			parent[b] = find_root(a);
			i++;
		}
		int a, b;
		std::cin >> a >> b;
		dfs(find_root(a), a, b);
	}
}
