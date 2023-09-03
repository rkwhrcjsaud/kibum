#include <iostream>
#include <vector>
#include <algorithm>

int n, m, cnt;
std::vector< std::vector <int> > v;
std::vector< bool > visited;

void	dfs(int a)
{
	visited[a] = true;
	int size = v[a].size();
	int i = 0;
	while (i < size)
	{
		if (visited[v[a][i]] == false)
		{
			cnt++;
			dfs(v[a][i]);
		}
		i++;
	}
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cin >> n >> m;
	v.resize(n + 1);
	visited.resize(n + 1, 0);
	int i = 0;
	while (i++ < m)
	{
		int j, k;
		std::cin >> j >> k;
		v[j].push_back(k);
		v[k].push_back(j);
	}
	dfs(1);
	std::cout << cnt << "\n";
}