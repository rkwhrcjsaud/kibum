#include <iostream>
#include <vector>
#include <queue>

#define SRC 2501
#define SINK 2502
#define INF 1000000000
#define MIN(a, b) (a < b ? a : b)
int N, M;
int graph[5][5] = {
	{ 10, 8, 7, 5, 1 },
	{ 8, 6, 4, 3, 1 },
	{ 7, 4, 3, 2, 1 },
	{ 5, 3, 2, 2, 1 },
	{ 1, 1, 1, 1, 0 }
};
int arr[2510];

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

std::vector < Edge* > v[2510];

void	add_edge(int s, int e, int capa, int cost)
{
	Edge *forward = new Edge(e, capa, -cost);
	Edge *reverse = new Edge(s, 0, cost);
	forward->reverse = reverse;
	reverse->reverse = forward;
	v[s].push_back(forward);
	v[e].push_back(reverse);
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cin >> N >> M;
	int i = 0;
	while (i < N)
	{
		std::string str;
		std::cin >> str;
		int j = 0;
		while (j < M)
		{
			int num = i * M + j + 1;
			if (str[j] != 'F')
				arr[num] = str[j] - 'A';
			else
				arr[num] = 4;
			j++;
		}
		i++;
	}
	i = 0;
	while (i < N)
	{
		int j = 1;
		while (j <= M)
		{
			int num = i * M + j;
			if ((i + j) % 2 == 1)
			{
				add_edge(SRC, num, 1, 0);
				if (j != M)
					add_edge(num, num + 1, INF, graph[arr[num]][arr[num + 1]]);
				if (j != 1)
					add_edge(num, num - 1, INF, graph[arr[num]][arr[num - 1]]);
				if (i != N - 1)
					add_edge(num, num + M, INF, graph[arr[num]][arr[num + M]]);
				if (i != 0)
					add_edge(num, num - M, INF, graph[arr[num]][arr[num - M]]);
			}
			add_edge(num, SINK, 1, 0);
			j++;
		}
		i++;
	}
	int result = 0;
	int cnt = 0;
	while (1)
	{
		Edge *prev[2510] = { NULL };
		int dist[2510];
		bool visited[2510] = { 0 };
		std::queue < int > q;
		std::fill(dist, dist + 2510, INF);
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
	std::cout << -result << "\n";
}