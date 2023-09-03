#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

int n, m, r;
std::vector< std::vector<int> > v;
std::queue< int > queue;
std::vector< bool > visited;
std::vector< int > ans;
int cnt;

int compare(int a, int b)
{
	return (a < b);
}

void	bfs(int a)
{
	if (a > n)
		return ;
	visited[a] = true;
	queue.push(a);
	ans[a] = ++cnt;
	while (!queue.empty())
	{
		int temp = queue.front();
		std::vector <int>::iterator iter = v[temp].begin();
		queue.pop();
		while (iter != v[temp].end())
		{
			if (visited[*iter] == false)
			{
				ans[*iter] = ++cnt;
				visited[*iter] = true;
				queue.push(*iter);
			}
			iter++;
		}
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
	ans.resize(n + 1, 0);
	while (i < m)
	{
		int j, k;
		std::cin >> j >> k;
		v[k].push_back(j);
		v[j].push_back(k);
		i++;
	}
	i = 1;
	while (i <= n)
	{
		std::sort(v[i].begin(), v[i].end(), compare);
		i++;
	}
	bfs(r);
	i = 1;
	while (i <= n)
		std::cout << ans[i++] << "\n";
}