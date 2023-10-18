#include <iostream>
#include <vector>

int N, M;
std::vector <int> v[1001];
int		pos[1001];
bool	visited[1001];

bool	dfs(int node)
{
	int i = 0;
	int size = v[node].size();
	while (i < size)
	{
		if (!visited[v[node][i]])
		{
			visited[v[node][i]] = true;
			if (pos[v[node][i]] == 0 || dfs(pos[v[node][i]]))
			{
				pos[v[node][i]] = node;
				return true;
			}
		}
		i++;
	}
	return false;
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cin >> N >> M;
	int i = 1;
	while (i <= N)
	{
		int L;
		std::cin >> L;
		int j = 1;
		while (j <= L)
		{
			int num;
			std::cin >> num;
			v[i].push_back(num);
			j++;
		}
		i++;
	}
	int cnt = 0;
	i = 1;
	while (i <= N)
	{
		std::fill(visited, visited + 1000, 0);
		if (dfs(i))
			cnt++;
		i++;
	}
	std::cout << cnt << "\n";
}