#include <iostream>
#include <vector>
#include <stack>
#include <queue>

#define SRC 101
#define SINK 102
#define INF 10000
#define MIN(a, b) (a < b ? a : b)
int N, row_sum;
int arr[110];
int c[110][110];
int f[110][110];
int level[110];
int work[110];
std::vector <int> v[110];

bool bfs(void)
{
	std::fill(level, level + 110, -1);
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

int	binary_search(int s, int e)
{
	if (s > e)
		return INF;
	if (s == e)
		return s;
	int mid = (s + e) / 2;
	int i = 1;
	while (i <= N)
	{
		int j = N + 1;
		while (j <= N << 1)
		{
			c[i][j] = mid;
			f[i][j] = 0;
			f[j][i] = 0;
			j++;
		}
		i++;
	}
	i = 1;
	while (i <= N)
	{
		f[SRC][i] = 0;
		f[i + N][SINK] = 0;
		i++;
	}
	int cnt = 0;
	while (bfs())
	{
		std::fill(work, work + 110, 0);
		while (1)
		{
			int flow = dfs(SRC, SINK, INF);
			if (flow == 0)
				break ;
			cnt += flow;
		}
	}
	if (cnt == row_sum)
		return MIN(mid, binary_search(s, mid));
	return binary_search(mid + 1, e);
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cin >> N;
	int i = 1;
	while (i <= N * 2)
	{
		std::cin >> arr[i];
		if (i <= N)
		{
			row_sum += arr[i];
			v[SRC].push_back(i);
			c[SRC][i] = arr[i];
		}
		else
		{
			v[i].push_back(SINK);
			c[i][SINK] = arr[i];
		}
		i++;
	}
	i = 1;
	while (i <= N)
	{
		int j = N + 1;
		while (j <= N << 1)
		{
			v[i].push_back(j);
			v[j].push_back(i);
			j++;
		}
		i++;
	}
	int ans = binary_search(0, 10000);
	std::cout << ans << "\n";
	i = 1;
	while (i <= N)
	{
		int j = N + 1;
		while (j <= N << 1)
		{
			c[i][j] = ans;
			f[i][j] = 0;
			f[j][i] = 0;
			j++;
		}
		i++;
	}
	i = 1;
	while (i <= N)
	{
		f[SRC][i] = 0;
		f[i + N][SINK] = 0;
		i++;
	}
	int cnt = 0;
	while (bfs())
	{
		std::fill(work, work + 110, 0);
		while (1)
		{
			int flow = dfs(SRC, SINK, INF);
			if (flow == 0)
				break ;
			cnt += flow;
		}
	}
	i = 1;
	while (i <= N)
	{
		int j = N + 1;
		while (j <= N << 1)
		{
			std::cout << f[i][j] << " ";
			j++;
		}
		std::cout << "\n";
		i++;
	}
}