#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define INF 200000000
#define MIN(a, b) (a < b ? a : b)

int T;
int min[2002];
std::vector < std::pair <int, int> > v[2002];

int compare(int a, int b)
{
	return (a < b);
}

void	bfs(int start)
{
	std::priority_queue < std::pair < int, int > > q;
	min[start] = 0;
	q.push(std::make_pair(0, start));
	while (!q.empty())
	{
		int w = q.top().first * -1;
		int node = q.top().second;
		q.pop();
		int i = 0;
		int size = v[node].size();
		while (i < size)
		{
			int next = v[node][i].first;
			int ww = v[node][i].second;
			if (min[next] > w + ww)
			{
				min[next] = w + ww;
				q.push(std::make_pair(min[next] * -1, next));
			}
			i++;
		}
	}
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cin >> T;
	while (T--)
	{
		int n, m, t, s, g, h;
		std::cin >> n >> m >> t >> s >> g >> h;
		int i = 0;
		while (i < m)
		{
			int a, b, d;
			std::cin >> a >> b >> d;
			d *= 2;
			if ((a == g && b == h) || (a == h && b == g))
				d--;
			v[a].push_back(std::make_pair(b, d));
			v[b].push_back(std::make_pair(a, d));
			i++;
		}
		i = 0;
		while (i < 2002)
			min[i++] = INF;
		bfs(s);
		std::vector < int > desti;
		i = 1;
		while (i <= t)
		{
			int temp = 0;
			std::cin >> temp;
			if (min[temp] != INF && min[temp] % 2 == 1)
				desti.push_back(temp);
			i++;
		}
		std::sort(desti.begin(), desti.end(), compare);
		i = 0;
		int size = desti.size();
		while (i < size)
			std::cout << desti[i++] << " ";
		std::cout << "\n";
		i = 0;
		while (i <= n)
			v[i++].clear();
	}
}