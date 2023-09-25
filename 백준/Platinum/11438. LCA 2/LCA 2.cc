#include <iostream>
#include <vector>

int N, M;
int	parent[100001][17];
bool visited[100001];
std::vector <int> v[100001];

int find_depth(int x)
{
	if (x == 1)
		return 0;
	if (parent[x][0] == 1)
		return 1;
	int depth = 0;
	int j = 16;
	while (x != 1)
	{
		if (j != 0 && parent[x][j] == 1)
			j--;
		else
		{
			x = parent[x][j];
			depth += 1 << j;
		}
	}
	return depth;
}

void	dfs(int x)
{
	std::vector <int> temp = v[x];
	int i = 0;
	int size = temp.size();
	visited[x] = 1;
	while (i < size)
	{
		if (visited[temp[i]] == 0)
		{
			parent[temp[i]][0] = x;
			dfs(temp[i]);
		}
		i++;
	}
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cin >> N;
	int i = 1;
	while (i <= N)
	{
		parent[i][0] = i;
		i++;
	}
	i = 1;
	while (i < N)
	{
		int a, b;
		std::cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
		i++;
	}
	dfs(1);
	i = 1;
	while (i < 17)
	{
		int j = 1;
		while (j <= N)
		{
			parent[j][i] = parent[parent[j][i - 1]][i - 1];
			j++;
		}
		i++;
	}
	std::cin >> M;
	i = 0;
	while (i < M)
	{
		int node1, node2;
		std::cin >> node1 >> node2;
		int depth1 = find_depth(node1);
		int depth2 = find_depth(node2);
		int depth_diff = abs(depth1 - depth2);
		int j = 0;
		while (depth_diff)
		{
			if (depth_diff & (1 << j))
			{
				if (depth1 > depth2)
					node1 = parent[node1][j];
				if (depth2 > depth1)
					node2 = parent[node2][j];
				depth_diff -= (1 << j);
				j = 0;
			}
			else
				j++;
		}
		j = 16;
		while (node1 != node2)
		{
			if (j != 0 && parent[node1][j] == parent[node2][j])
				j--;
			else
			{
				node1 = parent[node1][j];
				node2 = parent[node2][j];
			}
		}
		std::cout << node1 << "\n";
		i++;
	}
}
