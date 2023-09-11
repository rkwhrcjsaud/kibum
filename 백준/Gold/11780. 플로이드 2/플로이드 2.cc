#include <iostream>
#include <vector>

#define INF 10000002
#define MIN(a, b) (a < b ? a : b)

int n, m;
std::vector < std::pair <int, int> > v[102];
int min[102][102];
int route[102][102];
std::vector < int > v2;

void	find_node(int i, int j)
{
	if (route[i][j] == 0)
	{
		v2.push_back(i);
		v2.push_back(j);
		return ;
	}
	find_node(i, route[i][j]);
	v2.pop_back();
	find_node(route[i][j], j);
}

void	floyd(void)
{
	int i = 1;
	while (i <= n)
	{
		int j = 1;
		while (j <= n)
		{
			int k = 1;
			while (k <= n)
			{
				if (min[j][k] > min[j][i] + min[i][k])
				{
					min[j][k] = min[j][i] + min[i][k];
					route[j][k] = i;
				}
				k++;
			}
			j++;
		}
		i++;
	}
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cin >> n >> m;
	int i = 0;
	while (i < m)
	{
		int a, b, c;
		std::cin >> a >> b >> c;
		v[a].push_back(std::make_pair(b, c));
		if (!min[a][b] || min[a][b] > c)
			min[a][b] = c;
		i++;
	}
	i = 1;
	while (i <= n)
	{
		int j = 1;
		while (j <= n)
		{
			if (i != j && !min[i][j])
				min[i][j] = INF;
			j++;
		}
		i++;
	}
	floyd();
	i = 1;
	while (i <= n)
	{
		int j = 1;
		while (j <= n)
		{
			if (min[i][j] == INF)
				std::cout << "0 ";
			else
				std::cout << min[i][j] << " ";
			j++;
		}
		std::cout << "\n";
		i++;
	}
	i = 1;
	while (i <= n)
	{
		int j = 1;
		while (j <= n)
		{
			if (min[i][j] == 0 || min[i][j] == INF)
				std::cout << "0";
			else
			{
				v2.clear();
				find_node(i, j);
				std::cout << v2.size() << " ";
				int k = 0;
				int size = v2.size();
				while (k < size)
					std::cout << v2[k++] << " ";
			}
			std::cout << "\n";
			j++;
		}
		i++;
	}
}