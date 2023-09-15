#include <iostream>
#include <vector>
#include <algorithm>

int N, M;
bool	map[11][11];
std::pair <int, int> parent[11][11];
std::vector < std::pair < std::pair < std::pair < int, int >, std::pair < int, int > >, int > > v;

std::pair <int, int> find_root(std::pair <int, int> x)
{
	if (x != parent[x.first][x.second])
		return (parent[x.first][x.second] = find_root(parent[x.first][x.second]));
	return (parent[x.first][x.second]);
}

int compare(std::pair < std::pair < std::pair < int, int >, std::pair < int, int > >, int > a,
	std::pair < std::pair < std::pair < int, int >, std::pair < int, int > >, int > b)
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
		int j = 1;
		while (j <= M)
		{
			std::cin >> map[i][j];
			parent[i][j] = std::make_pair(i, j);
			j++;
		}
		i++;
	}
	i = 1;
	int flag = 0;
	std::pair <int, int> root;
	while (i <= N)
	{
		int j = 1;
		while (j <= M)
		{
			if (map[i][j] == true)
			{
				if (flag == 0)
				{
					flag = 1;
					root = find_root(std::make_pair(i, j));
				}
				std::pair <int, int> root_a = find_root(std::make_pair(i, j));
				if (map[i - 1][j])
				{
					std::pair <int, int> root_b = find_root(std::make_pair(i - 1, j));
					parent[root_b.first][root_b.second] = root_a;
				}
				if (map[i][j - 1])
				{
					std::pair <int, int> root_b = find_root(std::make_pair(i, j - 1));
					parent[root_b.first][root_b.second] = root_a;
				}
				int x = 0;
				while (j + x + 1 <= M && map[i][j + x + 1] != true)
					x++;
				if (j + x + 1 <= M && x >= 2)
					v.push_back(std::make_pair(std::make_pair(std::make_pair(i, j), std::make_pair(i, j + x + 1)), x));
				int y = 0;
				while (i + y + 1 <= N && map[i + y + 1][j] != true)
					y++;
				if (i + y + 1 <= N && y >= 2)
					v.push_back(std::make_pair(std::make_pair(std::make_pair(i, j), std::make_pair(i + y + 1, j)), y));
			}
			j++;
		}
		i++;
	}
	std::sort(v.begin(), v.end(), compare);
	i = 0;
	int size = v.size();
	int len = 0;
	while (i < size)
	{
		std::pair <int, int> root_a = find_root(std::make_pair(v[i].first.first.first, v[i].first.first.second));
		std::pair <int, int> root_b = find_root(std::make_pair(v[i].first.second.first, v[i].first.second.second));
		if (root_a != root_b)
		{
			len += v[i].second;
			parent[root_b.first][root_b.second] = root_a;
		}
		i++;
	}
	i = 1;
	while (i <= N)
	{
		int j = 1;
		while (j <= M)
		{
			if (map[i][j] && find_root(root) != find_root(std::make_pair(i, j)))
			{
				std::cout << "-1\n";
				return 0;
			}
			j++;
		}
		i++;
	}
	std::cout << len << "\n";
}