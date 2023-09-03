#include <iostream>
#include <algorithm>
#include <vector>

int n, m, r;
std::vector< std::vector<int> > v;
std::vector< bool > visited;
std::vector< int > ans;
int cnt;

int compare(int a, int b)
{
	return (a < b);
}

void	dfs(int a)
{
	if (a > n)
		return ;
	visited[a] = true;
	ans[a] = ++cnt;
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
	ans.resize(n + 1, 0);
	while (i < m)
	{
		int j, k;
		std::cin >> j >> k;
		v[k].push_back(j);
		v[j].push_back(k);
		i++;
	}
	i = 0;
	while (i < n)
	{
		std::sort(v[i].begin(), v[i].end(), compare);
		i++;
	}
	dfs(r);
	i = 1;
	while (i <= n)
		std::cout << ans[i++] << "\n";
}