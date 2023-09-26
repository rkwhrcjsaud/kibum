#include <iostream>
#include <vector>
#include <stack>
#include <cstring>
#include <algorithm>

int V, E;
std::vector <int> v[10001];
std::vector <int> r[10001];
bool	visited[10001];
std::stack <int> s;
int idx;
std::vector <int> ans[10001];

void	dfs_s(int x)
{
	visited[x] = true;
	std::vector <int> temp = r[x];
	int i = 0;
	int size = temp.size();
	while (i < size)
	{
		if (visited[temp[i]] == 0)
			dfs_s(temp[i]);
		i++;
	}
	ans[idx].push_back(x);
}

void	dfs_v(int x)
{
	visited[x] = true;
	int i = 0;
	std::vector <int> temp = v[x];
	int size = temp.size();
	while (i < size)
	{
		if (visited[temp[i]] == 0)
			dfs_v(temp[i]);
		i++;
	}
	s.push(x);
}

int compare(std::vector <int> a, std::vector <int> b)
{
	return (a[0] < b[0]);
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
		r[b].push_back(a);
		i++;
	}
	i = 1;
	while (i <= V)
	{
		if (visited[i] == 0)
			dfs_v(i);
		i++;
	}
	std::memset(visited, 0, sizeof(visited));
	while (!s.empty())
	{
		if (visited[s.top()] == 0)
		{
			dfs_s(s.top());
			idx++;
		}
		s.pop();
	}
	i = 0;
	std::cout << idx << "\n";
	while (i < idx)
	{
		int j = 0;
		int size = ans[i].size();
		std::sort(ans[i].begin(), ans[i].end());
		i++;
	}
	std::sort(ans, ans + idx, compare);
	i = 0;
	while (i < idx)
	{
		int j = 0;
		int size = ans[i].size();
		while (j < size)
			std::cout << ans[i][j++] << " ";
		std::cout << "-1\n";
		i++;
	}
}