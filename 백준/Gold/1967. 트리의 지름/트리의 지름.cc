#include <iostream>
#include <vector>
#include <cstring>

int V, max[2];
std::vector < std::pair <int, int> > v[100002];
bool visited[100002];

void	dfs2(int n, int sum)
{
	visited[n] = true;
	int i = 0;
	int size = v[n].size();
	while (i < size)
	{
		int next = v[n][i].first;
		int w = v[n][i].second;
		if (visited[next] == false)
		{
			visited[next] = true;
			dfs2(next, sum + w);
			visited[next] = false;
		}
		else if (max[0] < sum)
		{
			max[0] = sum;
			max[1] = n;
		}
		i++;
	}
	visited[n] = false;
}

void	dfs1(int n, int sum)
{
	visited[n] = true;
	int i = 0;
	int size = v[n].size();
	while (i < size)
	{
		int next = v[n][i].first;
		int w = v[n][i].second;
		if (visited[next] == false)
		{
			visited[next] = true;
			dfs1(next, sum + w);
			visited[next] = false;
		}
		else if (max[0] < sum)
		{
			max[0] = sum;
			max[1] = n;
		}
		i++;
	}
	visited[n] = false;
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cin >> V;
	int i = 0;
	while (i < V - 1)
	{
		int a, b, c;
		std::cin >> a >> b >> c;
		v[a].push_back(std::make_pair(b, c));
		v[b].push_back(std::make_pair(a, c));
		i++;
	}
	dfs1(1, 0);
	int temp = max[1];
	max[0] = 0;
	max[1] = 0;
	dfs2(temp, 0);
	std::cout << max[0] << "\n";
}
