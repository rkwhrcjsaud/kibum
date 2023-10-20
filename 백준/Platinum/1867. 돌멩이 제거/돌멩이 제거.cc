#include <iostream>
#include <vector>

int N, K;
std::vector <int> v[501];
bool visited[501];
int pos[501];

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
	std::cin >> N >> K;
	int i = 1;
	while (i <= K)
	{
		int y, x;
		std::cin >> y >> x;
		v[y].push_back(x);
		i++;
	}
	int cnt = 0;
	i = 1;
	while (i <= N)
	{
		std::fill(visited, visited + 501, 0);
		if (dfs(i))
			cnt++;
		i++;
	}
	std::cout << cnt << "\n";
}
