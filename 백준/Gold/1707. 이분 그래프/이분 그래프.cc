#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>

int K;
std::vector <int > v[20002];
std::queue < std::vector < int > > q;
int color[20002];
int checked[20002];

std::vector <int> make_vector(int a, int b, int c)
{
	std::vector <int> temp;
	temp.push_back(a);
	temp.push_back(b);
	temp.push_back(c);
	return (temp);
}

int	bfs(int a)
{
	color[a] = 1;
	checked[a] = 1;
	std::vector <int> ::iterator iter = v[a].begin();
	while (iter != v[a].end())
	{
		q.push(make_vector(a, *iter, 0));
		iter++;
	}
	while (!q.empty())
	{
		int start = q.front()[0];
		int end = q.front()[1];
		int level = q.front()[2];
		q.pop();
		if (color[end] == 0)
		{
			checked[end] = 1;
			color[end] = level % 2 == 1 ? 1 : -1;
			iter = v[end].begin();
			while (iter != v[end].end())
			{
				q.push(make_vector(end, *iter, level + 1));
				iter++;
			}
		}
		else if (color[end] != (level % 2 == 1 ? 1 : -1))
			return 1;
	}
	return 0;
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cin >> K;
	while (K--)
	{
		int V, E;
		std::cin >> V >> E;
		int i = 0;
		while (i < E)
		{
			int start, end;
			std::cin >> start >> end;
			v[start].push_back(end);
			v[end].push_back(start);
			i++;
		}
		i = 1;
		while (i < V)
		{
			if (checked[i])
			{
				i++;
				continue ;
			}
			int p = bfs(i);
			while (!q.empty())
				q.pop();
			int j = 1;
			while (j <= V)
				color[j++] = 0;
			if (p == 1)
			{
				std::cout << "NO\n";
				break ;
			}
			i++;
		}
		if (i == V)
			std::cout << "YES\n";
		i = 1;
		while (i <= V)
		{
			v[i].clear();
			checked[i++] = 0;
		}
	}
}