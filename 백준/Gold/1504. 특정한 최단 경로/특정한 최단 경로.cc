#include <iostream>
#include <vector>
#include <queue>

#define MIN(a, b) (a > b ? b : a)
#define INF 3000001

int V, E;
int node1, node2;
std::vector < std::pair< int, int > > v[20002];
int min[20002];
int ans;

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
	std::priority_queue < std::pair < int, int > > q;
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
	std::cin >> V >> E;
	int i = 0;
	while (i < E)
	{
		int a, b, c;
		std::cin >> a >> b >> c;
		v[a].push_back(std::make_pair(b, c));
		v[b].push_back(std::make_pair(a, c));
		i++;
	}
	std::cin >> node1 >> node2;
	i = 1;
	while (i <= V)
		min[i++] = INF;
	bfs(1);
	int start_to_node1 = min[node1];
	int start_to_node2 = min[node2];
	i = 1;
	while (i <= V)
		min[i++] = INF;
	bfs(node1);
	int node1_to_node2 = min[node2];
	int node1_to_end = min[V];
	i = 1;
	while (i <= V)
		min[i++] = INF;
	bfs(node2);
	int node2_to_end = min[V];
	ans = MIN(start_to_node1 + node1_to_node2 + node2_to_end, start_to_node2 + node1_to_node2 + node1_to_end);
	if (ans >= INF)
		std::cout << "-1\n";
	else
		std::cout << ans << "\n";
}