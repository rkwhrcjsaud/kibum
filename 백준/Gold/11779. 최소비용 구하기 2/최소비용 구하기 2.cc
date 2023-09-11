#include <iostream>
#include <vector>
#include <queue>
#include <stack>

#define MIN(a, b) (a > b ? b : a)
#define INF 200000000

int V, E, K, D;
std::vector < std::pair< int, int > > v[1002];
std::priority_queue < std::pair < int, int > > q;
int min[1002][2];

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
	min[k][0] = 0;
	q.push(std::make_pair(0, k));
	while (!q.empty())
	{
		int w = q.top().first * -1;
		int node = q.top().second;
		if (node == D)
			return ;
		q.pop();
		int i = 0;
		int size = v[node].size();
		while (i < size)
		{
			int next = v[node][i].first;
			int ww = v[node][i].second;
			if (min[next][0] > w + ww)
			{
				min[next][0] = w + ww;
				min[next][1] = node;
				q.push(std::make_pair(min[next][0] * -1, next));
			}
			i++;
		}
	}
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cin >> V >> E;
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
	{
		min[i][1] = -1;
		min[i++][0] = INF;
	}
	std::cin >> K >> D;
	bfs(K);
	std::cout << min[D][0] << "\n";
	std::stack <int> s;
	s.push(D);
	while (min[D][1] != -1)
	{
		s.push(min[D][1]);
		D = min[D][1];
	}
	std::cout << s.size() << "\n";
	while (!s.empty())
	{
		std::cout << s.top() << " ";
		s.pop();
	}
	std::cout << "\n";
}