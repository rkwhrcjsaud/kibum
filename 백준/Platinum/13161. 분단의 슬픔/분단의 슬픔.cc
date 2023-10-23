#include <iostream>
#include <vector>
#include <queue>

#define SRC 501
#define SINK 502
#define INF 2147483647
#define MIN(a, b) (a < b ? a : b)
int N;
int c[505][505], f[505][505];
int level[505], work[505];
std::vector <int> v[505];
bool visited[505];

bool bfs(void)
{
	std::fill(level, level + 505, -1);
	level[SRC] = 0;
	std::queue <int> q;
	q.push(SRC);
	while (!q.empty())
	{
		int curr = q.front();
		q.pop();
		int i = 0;
		int size = v[curr].size();
		while (i < size)
		{
			int next = v[curr][i];
			if (level[next] == -1 && c[curr][next] > f[curr][next])
			{
				level[next] = level[curr] + 1;
				q.push(next);
			}
			i++;
		}
	}
	return (level[SINK] != -1);
}

int dfs(int curr, int dest, int flow)
{
	if (curr == dest)
		return flow;
	int size = v[curr].size();
	while (work[curr] < size)
	{
		int next = v[curr][work[curr]];
		if (level[next] == level[curr] + 1 && c[curr][next] > f[curr][next])
		{
			int df = dfs(next, dest, MIN(c[curr][next] - f[curr][next], flow));
			if (df > 0)
			{
				f[curr][next] += df;
				f[next][curr] -= df;
				return df;
			}
		}
		work[curr]++;
	}
	return 0;
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cin >> N;
	int i = 1;
	while (i <= N)
	{
		int tmp;
		std::cin >> tmp;
		if (tmp == 1)
		{
			v[SRC].push_back(i);
			v[i].push_back(SRC);
			c[SRC][i] = INF;
		}
		else if (tmp == 2)
		{
			v[i].push_back(SINK);
			v[SINK].push_back(i);
			c[i][SINK] = INF;
		}
		i++;
	}
	i = 1;
	while (i <= N)
	{
		int j = 0;
		while (++j <= N)
		{
			int tmp;
			std::cin >> tmp;
			if (i == j)
				continue ;
			v[i].push_back(j);
			c[i][j] = tmp;
		}
		i++;
	}
	int cnt = 0;
	while (bfs())
	{
		std::fill(work, work + 505, 0);
		while (1)
		{
			int flow = dfs(SRC, SINK, INF);
			if (flow == 0)
				break ;
			cnt += flow;
		}
	}
	std::cout << cnt << "\n";
	visited[SRC] = true;
	std::queue <int> q;
	q.push(SRC);
	while (!q.empty())
	{
		int curr = q.front();
		q.pop();
		int i = 0;
		int size = v[curr].size();
		while (i < size)
		{
			int next = v[curr][i];
			if (!visited[next] && c[curr][next] > f[curr][next])
			{
				visited[next] = true;
				q.push(next);
			}
			i++;
		}
	}
	i = 1;
	while (i <= N)
	{
		if (visited[i])
			std::cout << i << " ";
		i++;
	}
	std::cout << "\n";
	i = 1;
	while (i <= N)
	{
		if (!visited[i])
			std::cout << i << " ";
		i++;
	}
	std::cout << "\n";
}