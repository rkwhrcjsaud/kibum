#include <iostream>
#include <cstring>
#include <vector>

bool visited[502];
std::vector <int> v[502];

int dfs(int past, int s)
{
	visited[s] = true;
	int i = 0;
	int size = v[s].size();
	int ans = 1;
	while (i < size)
	{
		if (s == v[s][i])
			ans = 0;
		if (past != v[s][i] && visited[v[s][i]] == true)
			ans = 0;
		if (visited[v[s][i]] == false)
		{
			int temp = dfs(s, v[s][i]);
			if (ans == 1)
				ans = temp;
		}
		i++;
	}
	return ans;
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	int c = 1;
	while (1)
	{
		int n, m;
		std::cin >> n >> m;
		if (n == 0 && m == 0)
			return (0);
		int i = 0;
		while (i < m)
		{
			int a, b;
			std::cin >> a >> b;
			v[a].push_back(b);
			v[b].push_back(a);
			i++;
		}
		i = 1;
		int cnt = 0;
		while (i <= n)
		{
			if (visited[i] == true)
			{
				i++;
				continue ;
			}
			cnt += dfs(0, i++);
		}
		std::cout << "Case " << c << ": ";
		if (cnt > 1)
			std::cout << "A forest of " << cnt << " trees.\n";
		else if (cnt == 1)
			std::cout << "There is one tree.\n";
		else
			std::cout << "No trees.\n";
		c++;
		i = 0;
		while (i <= n)
		{
			visited[i] = false;
			v[i++].clear();
		}
	}
}