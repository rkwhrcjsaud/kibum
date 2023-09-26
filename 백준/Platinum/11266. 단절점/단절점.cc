#include <iostream>
#include <vector>

#define MIN(a, b) (a < b ? a : b)

int V, E;
std::vector <int> v[10001];
int	visited[10001];
bool	dot[10001];
int	order;

int dfs(int x, bool	isroot)
{
	order++;
	visited[x] = order;
	std::vector <int> temp = v[x];
	int i = 0;
	int size = temp.size();
	int child = 0;
	int min_order = order;
	while (i < size)
	{
		if (visited[temp[i]] == 0)
		{
			child++;
			int num = dfs(temp[i], 0);
			min_order = MIN(num, min_order);
			if (!isroot && num >= visited[x])
				dot[x] = true;
		}
		else
			min_order = MIN(min_order, visited[temp[i]]);
		i++;
	}
	if (isroot && child > 1)
		dot[x] = true;
	return min_order;
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cin >> V >> E;
	int i = 0;
	while (i < E)
	{
		int a, b;
		std::cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
		i++;
	}
	i = 1;
	while (i <= V)
	{
		if (visited[i] == 0)
			dfs(i, 1);
		i++;
	}
	i = 0;
	int cnt = 0;
	while (i <= V)
	{
		if (dot[i])
			cnt++;
		i++;
	}
	std::cout << cnt << "\n";
	i = 0;
	while (i <= V)
	{
		if (dot[i])
			std::cout << i << " ";
		i++;
	}
	std::cout << "\n";
}