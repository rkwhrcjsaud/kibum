#include <iostream>
#include <vector>
#include <stack>

#define SRC 2001
#define BRIDGE 2002
#define SINK 2003
#define MIN(a, b) (a < b ? a : b)
int N, M, K;
std::vector <int> v[2005];
int c[2005][2005];
int f[2005][2005];

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cin >> N >> M >> K;
	v[SRC].push_back(BRIDGE);
	v[BRIDGE].push_back(SRC);
	c[SRC][BRIDGE] = K;
	int i = 1;
	while (i <= N)
	{
		v[SRC].push_back(i);
		v[i].push_back(SRC);
		c[SRC][i] = 1;
		v[BRIDGE].push_back(i);
		v[i].push_back(BRIDGE);
		c[BRIDGE][i] = K;
		int L;
		std::cin >> L;
		int j = 1;
		while (j <= L)
		{
			int num;
			std::cin >> num;
			v[i].push_back(num + 1000);
			v[num + 1000].push_back(i);
			c[i][num + 1000] = 1;
			j++;
		}
		i++;
	}
	i = 1001;
	while (i <= M + 1000)
	{
		v[i].push_back(SINK);
		v[SINK].push_back(i);
		c[i][SINK] = 1;
		i++;
	}
	int cnt = 0;
	while (1)
	{
		int prev[2005];
		std::fill(prev, prev + 2005, -1);
		std::stack < int > q;
		q.push(SRC);
		while (!q.empty())
		{
			int curr = q.top();
			q.pop();
			i = 0;
			int size = v[curr].size();
			while (i < size)
			{
				int next = v[curr][i];
				if (prev[next] == -1 && c[curr][next] > f[curr][next])
				{
					q.push(next);
					prev[next] = curr;
					if (next == SINK)
						break ;
				}
				i++;
			}
		}
		if (prev[SINK] == -1)
			break ;
		i = SINK;
		int min = 2000;
		while (i != SRC)
		{
			min = MIN(min, c[prev[i]][i] - f[prev[i]][i]);
			i = prev[i];
		}
		i = SINK;
		while (i != SRC)
		{
			f[prev[i]][i] += min;
			f[i][prev[i]] -= min;
			i = prev[i];
		}
		cnt += min;
	}
	std::cout << cnt << "\n";
}