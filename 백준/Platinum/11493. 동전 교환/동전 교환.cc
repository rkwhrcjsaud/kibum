#include <iostream>
#include <vector>
#include <queue>

#define SRC 501
#define SINK 502
#define INF 1000000000
#define MIN(a, b) (a < b ? a : b)
int T, N, M;

class Edge
{
	public :
		int target;
		int cost;
		int capacity;
		int flow;
		Edge* reverse;
		Edge(int target, int capa, int cost)
			: target(target), cost(cost), capacity(capa), flow(0)
		{};
		int remain_c()
		{
			return capacity - flow;
		}
		void push(int amount)
		{
			flow += amount;
			reverse->flow -= amount;
		}
};

std::vector < Edge* > v[510];

void	add_edge(int s, int e, int capa, int cost)
{
	Edge *forward = new Edge(e, capa, cost);
	Edge *reverse = new Edge(s, 0, -cost);
	forward->reverse = reverse;
	reverse->reverse = forward;
	v[s].push_back(forward);
	v[e].push_back(reverse);
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cin >> T;
	while (T--)
	{
		std::cin >> N >> M;
		int i = 1;
		while (i < 510)
			v[i++].clear();
		i = 1;
		while (i <= M)
		{
			int x, y;
			std::cin >> x >> y;
			add_edge(x, y, INF, 1);
			add_edge(y, x, INF, 1);
			i++;
		}
		i = 1;
		while (i <= N)
		{
			bool white;
			std::cin >> white;
			if (white)
				add_edge(SRC, i, 1, 0);
			i++;
		}
		i = 1;
		while (i <= N)
		{
			bool white;
			std::cin >> white;
			if (white)
				add_edge(i, SINK, 1, 0);
			i++;
		}
		int result = 0;
		int cnt = 0;
		while (1)
		{
			Edge *prev[510] = { NULL };
			int dist[510];
			bool visited[510] = { 0 };
			std::queue < int > q;
			std::fill(dist, dist + 510, INF);
			dist[SRC] = 0;
			visited[SRC] = true;
			q.push(SRC);
			while (!q.empty())
			{
				int curr = q.front();
				q.pop();
				visited[curr] = false;
				i = 0;
				int size = v[curr].size();
				while (i < size)
				{
					Edge *next = v[curr][i];
					if (next->remain_c() > 0 && dist[next->target] > dist[curr] + next->cost)
					{
						dist[next->target] = dist[curr] + next->cost;
						prev[next->target] = next;
						if (!visited[next->target])
						{
							q.push(next->target);
							visited[next->target] = true;
						}
					}
					i++;
				}
			}
			if (prev[SINK] == NULL)
				break ;
			int flow = INF;
			i = SINK;
			while (i != SRC)
			{
				flow = MIN(flow, prev[i]->remain_c());
				i = prev[i]->reverse->target;
			}
			i = SINK;
			while (i != SRC)
			{
				result += flow * prev[i]->cost;
				prev[i]->push(flow);
				i = prev[i]->reverse->target;
			}
			cnt++;
		}
		std::cout << result << "\n";
	}
}