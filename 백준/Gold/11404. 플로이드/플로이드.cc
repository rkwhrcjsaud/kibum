#include <iostream>
#include <vector>

#define INF 10000002
#define MIN(a, b) (a < b ? a : b)

int n, m;
std::vector < std::pair <int, int> > v[102];
int min[102][102];

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
				min[j][k] = MIN(min[j][k], min[j][i] + min[i][k]);
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
}