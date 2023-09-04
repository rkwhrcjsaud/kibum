#include <iostream>
#include <queue>

#define INF 100000
int N, K;
int min[200002];
std::priority_queue < std::pair <int, int> > q;

void	bfs(void)
{
	int n = N;
	min[n] = 0;
	q.push(std::make_pair(0, n));
	while (!q.empty())
	{
		int	w = q.top().first * -1;
		int node = q.top().second;
		q.pop();
		while (node <= 200000)
		{
			if (node + 1 <= 200000 && min[node + 1] > w + 1)
			{
				min[node + 1] = w + 1;
				q.push(std::make_pair((w + 1) * -1, node + 1));
			}
			if (node - 1 >= 0 && min[node - 1] > w + 1)
			{
				min[node - 1] = w + 1;
				q.push(std::make_pair((w + 1) * -1, node - 1));
			}
			if (node == 0)
				break ;
			if (node <= 200000 && min[node] > w)
			{
				min[node] = w;
				q.push(std::make_pair(w * -1, node));
			}
			node = node << 1;
		}
	}
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cin >> N >> K;
	int i = 0;
	while (i <= 200001)
		min[i++] = INF;
	bfs();
	std::cout << min[K] << "\n";
}