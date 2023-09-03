#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

int n, m, r;
std::vector< std::vector<int> > v;
std::vector< bool > visited;
std::queue< int > queue;

int compare(int a, int b)
{
	return (a < b);
}

void	bfs(int a)
{
	if (a > n)
		return ;
	visited[a] = true;
	std::cout << a << " ";
	queue.push(a);
	while (!queue.empty())
	{
		int temp = queue.front();
		std::vector <int>::iterator iter = v[temp].begin();
		queue.pop();
		while (iter != v[temp].end())
		{
			if (visited[*iter] == false)
			{
				std::cout << *iter << " ";
				visited[*iter] = true;
				queue.push(*iter);
			}
			iter++;
		}
	}
}
void	dfs(int a)
{
	if (a > n)
		return ;
	visited[a] = true;
	std::cout << a << " ";
	std::vector <int>::iterator iter = v[a].begin();
	while (iter != v[a].end())
	{
		if (visited[*iter] == false)
			dfs(*iter);
		iter++;
	}
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cin >> n >> m >> r;
	int i = 0;
	v.resize(n + 1);
	visited.resize(n + 1, 0);
	while (i < m)
	{
		int j, k;
		std::cin >> j >> k;
		v[k].push_back(j);
		v[j].push_back(k);
		i++;
	}
	i = 0;
	while (i <= n)
	{
		std::sort(v[i].begin(), v[i].end(), compare);
		i++;
	}
	dfs(r);
	std::cout << "\n";
	visited.clear();
	visited.resize(n + 1);
	bfs(r);
	std::cout << "\n";
}