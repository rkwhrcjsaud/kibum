#include <iostream>
#include <vector>
#include <queue>

#define MIN(a, b) (a > b ? b : a)
#define INF 3000001

int V, E, K;
std::vector < std::pair< int, int > > v[20002];
std::priority_queue < std::pair < int, int > > q;
int min[20002];

std::vector <int> make_vector(int a, int b, int c)
{
	std::vector <int> temp;
	temp.push_back(a);
	temp.push_back(b);
	temp.push_back(c);
	return (temp);
}

void	bfs(int k)
{
	min[k] = 0;
	q.push(std::make_pair(0, k));
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
	std::cin >> V >> E >> K;
	int i = 0;
	while (i < E)
	{
		int a, b, c;
		std::cin >> a >> b >> c;
		v[a].push_back(std::make_pair(b, c));
		i++;
	}
	i = 1;
	while (i <= V)
		min[i++] = INF;
	bfs(K);
	i = 1;
	while (i <= V)
	{
		if (min[i] == INF)
			std::cout << "INF\n";
		else
			std::cout << min[i] << "\n";
		i++;
	}
}