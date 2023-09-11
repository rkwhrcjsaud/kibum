#include <iostream>
#include <vector>
#include <queue>

int N;
std::vector < int > v[100002];
std::queue < int > q;
bool visited[100002];
int parents[100002];

void	bfs(void)
{
	q.push(1);
	visited[1] = 0;
	while (!q.empty())
	{
		int cur = q.front();
		int i = 0;
		int size = v[cur].size();
		q.pop();
		while (i < size)
		{
			if (visited[v[cur][i]] == false)
			{
				visited[v[cur][i]] = true;
				parents[v[cur][i]] = cur;
				q.push(v[cur][i]);
			}
			i++;
		}
	}
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cin >> N;
	int i = 1;
	while (i <= N - 1)
	{
		int a, b;
		std::cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
		i++;
	}
	bfs();
	i = 2;
	while (i <= N)
	{
		std::cout << parents[i] << "\n";
		i++;
	}
}