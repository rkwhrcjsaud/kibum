#include <iostream>
#include <vector>

typedef long long ll;

int N, Q;
std::vector <std::pair <int, ll> > v[100001];
std::pair <int, ll> parent[100001][17];
bool	visited[100001];

int find_depth(int x)
{
	if (x == 1)
		return 0;
	if (parent[x][0].first == 1)
		return 1;
	int depth = 0;
	int j = 16;
	while (x != 1)
	{
		if (j != 0 && parent[x][j].first == 1)
			j--;
		else
		{
			x = parent[x][j].first;
			depth += 1 << j;
		}
	}
	return depth;
}

void	dfs(int x)
{
	std::vector < std::pair < int, ll > > temp = v[x];
	int i = 0;
	int size = temp.size();
	visited[x] = 1;
	while (i < size)
	{
		if (visited[temp[i].first] == 0)
		{
			parent[temp[i].first][0] = std::make_pair(x, temp[i].second);
			dfs(temp[i].first);
		}
		i++;
	}
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cin >> N;
	int i = 0;
	while (++i <= N - 1)
	{
		int a, b, c;
		std::cin >> a >> b >> c;
		v[a].push_back(std::make_pair(b, c));
		v[b].push_back(std::make_pair(a, c));
		parent[i][0].first = i;
	}
	parent[N][0].first = N;
	dfs(1);
	i = 1;
	while (i < 17)
	{
		int j = 1;
		while (j <= N)
		{
			parent[j][i].first = parent[parent[j][i - 1].first][i - 1].first;
			parent[j][i].second = parent[j][i - 1].second + parent[parent[j][i - 1].first][i - 1].second;
			j++;
		}
		i++;
	}
	std::cin >> Q;
	i = 0;
	while (i < Q)
	{
		int flag, node1, node2;
		std::cin >> flag >> node1 >> node2;
		int save_node1 = node1;
		int save_node2 = node2;
		int depth1 = find_depth(node1);
		int depth2 = find_depth(node2);
		int depth_diff = abs(depth1 - depth2);
		ll	node1_w = 0;
		ll	node2_w = 0;
		int j = 0;
		while (depth_diff)
		{
			if (depth_diff & (1 << j))
			{
				if (depth1 > depth2)
				{
					node1_w += parent[node1][j].second;
					node1 = parent[node1][j].first;
				}
				if (depth2 > depth1)
				{
					node2_w += parent[node2][j].second;
					node2 = parent[node2][j].first;
				}
				depth_diff -= (1 << j);
				j = 0;
			}
			else
				j++;
		}
		j = 16;
		while (node1 != node2)
		{
			if (j != 0 && parent[node1][j].first == parent[node2][j].first)
				j--;
			else
			{
				node1_w += parent[node1][j].second;
				node1 = parent[node1][j].first;
				node2_w += parent[node2][j].second;
				node2 = parent[node2][j].first;
			}
		}
		if (flag == 2)
		{
			int lca = node1;
			int lca_depth = find_depth(lca);
			int k;
			std::cin >> k;
			if (k <= depth1 - lca_depth)
			{
				k--;
				j = 0;
				while (k)
				{
					if (k & (1 << j))
					{
						save_node1 = parent[save_node1][j].first;
						k -= (1 << j);
						j = 0;
					}
					else
						j++;
				}
				std::cout << save_node1 << "\n";
			}
			else if (k > depth1 - lca_depth)
			{
				k = (depth1 + depth2 - 2 * lca_depth + 1) - k;
				j = 0;
				while (k)
				{
					if (k & (1 << j))
					{
						save_node2 = parent[save_node2][j].first;
						k -= (1 << j);
						j = 0;
					}
					else
						j++;
				}
				std::cout << save_node2 << "\n";
			}
		}
		else
			std::cout << node1_w + node2_w << "\n";
		i++;
	}
}
