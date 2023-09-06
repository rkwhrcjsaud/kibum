#include <iostream>
#include <vector>
#include <queue>

#define INF 5000001

int N, M, A, B, C;
std::vector < std::pair <int, int> > v[502];
long long	min[502];

int	bfs(int s)
{
	min[s] = 0;
	int idx = 1;
	while (idx <= N)
	{
		int i = 1;
		while (i <= N)
		{
			int cur = i;
			int j = 0;
			int size = v[i].size();
			while (j < size)
			{
				int next = v[i][j].first;
				int w = v[i][j].second;
				if (min[cur] != INF && min[next] > min[cur] + w)
				{
					min[next] = min[cur] + w;
					if (idx == N)
						return 1;
				}
				j++;
			}
			i++;
		}
		idx++;
	}
	return 0;
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cin >> N >> M;
	int i = 0;
	while (i < M)
	{
		std::cin >> A >> B >> C;
		v[A].push_back(std::make_pair(B, C));
		i++;
	}
	i = 0;
	while (i < 502)
		min[i++] = INF;
	if (bfs(1))
	{
		std::cout << "-1\n";
		return 0;
	}
	i = 2;
	while (i <= N)
	{
		if (min[i] == INF)
			std::cout << "-1\n";
		else
			std::cout << min[i] << "\n";
		i++;
	}
}