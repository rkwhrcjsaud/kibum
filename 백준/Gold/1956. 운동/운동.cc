#include <iostream>

#define INF 40000002
#define MIN(a, b) (a < b ? a : b)

int n, m, ans;
int min[402][402];

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
	ans = INF;
	i = 1;
	while (i <= n)
	{
		int j = i + 1;
		while (j <= n)
		{
			ans = MIN(ans, min[i][j] + min[j][i]);
			j++;
		}
		i++;
	}
	if (ans == INF)
		std::cout << "-1\n";
	else
		std::cout << ans << "\n";
}