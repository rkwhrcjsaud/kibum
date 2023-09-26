#include <iostream>
#include <vector>

#define MAX(a, b) (a > b ? a : b)
#define MIN(a, b) (a < b ? a : b)
#define INF 1000001

int N, K;
std::vector < std::pair <int, int> > v[100001];
std::pair <int, std::pair <int, int> > 	parent[100001][17];
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
	std::vector < std::pair < int, int > > temp = v[x];
	int i = 0;
	int size = temp.size();
	visited[x] = 1;
	while (i < size)
	{
		if (visited[temp[i].first] == 0)
		{
			parent[temp[i].first][0] = std::make_pair(x, std::make_pair(temp[i].second, temp[i].second));
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
	int i = 1;
	while (i < N)
	{
		int a, b, c;
		std::cin >> a >> b >> c;
		v[a].push_back(std::make_pair(b, c));
		v[b].push_back(std::make_pair(a, c));
		parent[i][0].first = i;
		parent[i][0].second.first = 0;
		parent[i][0].second.second = INF;
		i++;
	}
	parent[N][0].first = N;
	parent[N][0].second.first = 0;
	parent[N][0].second.second = INF;
	dfs(1);
	i = 1;
	while (i < 17)
	{
		int j = 1;
		while (j <= N)
		{
			int parent_x = parent[parent[j][i - 1].first][i - 1].first;
			int min = MIN(parent[parent[j][i - 1].first][i - 1].second.second, parent[j][i - 1].second.second);
			int max = MAX(parent[parent[j][i - 1].first][i - 1].second.first, parent[j][i - 1].second.first);
			parent[j][i] = std::make_pair(parent_x, std::make_pair(max, min));
			j++;
		}
		i++;
	}
	std::cin >> K;
	i = 0;
	while (i < K)
	{
		int node1, node2;
		std::cin >> node1 >> node2;
		int depth1 = find_depth(node1);
		int depth2 = find_depth(node2);
		int depth_diff = abs(depth1 - depth2);
		int min = INF, max = 0;
		int j = 0;
		while (depth_diff)
		{
			if (depth_diff & (1 << j))
			{
				if (depth1 > depth2)
				{
					min = MIN(min, parent[node1][j].second.second);
					max = MAX(max, parent[node1][j].second.first);
					node1 = parent[node1][j].first;
				}
				if (depth2 > depth1)
				{
					min = MIN(min, parent[node2][j].second.second);
					max = MAX(max, parent[node2][j].second.first);
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
				min = MIN(min, parent[node1][j].second.second);
				max = MAX(max, parent[node1][j].second.first);
				node1 = parent[node1][j].first;
				min = MIN(min, parent[node2][j].second.second);
				max = MAX(max, parent[node2][j].second.first);
				node2 = parent[node2][j].first;
			}
		}
		std::cout << min << " " << max << "\n";
		i++;
	}
}