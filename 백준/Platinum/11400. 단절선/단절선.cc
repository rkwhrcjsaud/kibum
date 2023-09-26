#include <iostream>
#include <vector>
#include <algorithm>

#define MIN(a, b) (a < b ? a : b)
#define MAX(a, b) (a > b ? a : b)

int V, E;
std::vector <int> v[100001];
int	visited[100001];
bool	dot[100001];
std::vector <std::pair <int, int> > ans;
int	order;

int dfs(int x, int parent)
{
	order++;
	visited[x] = order;
	std::vector <int> temp = v[x];
	int i = 0;
	int size = temp.size();
	int min_order = order;
	int child = 0;
	while (i < size)
	{
		if (temp[i] == parent)
			;
		else if (visited[temp[i]] == 0)
		{
			int num = dfs(temp[i], x);
			min_order = MIN(num, min_order);
			if (num > visited[x])
			{
				int small = MIN(x, temp[i]);
				int big = MAX(x, temp[i]);
				ans.push_back(std::make_pair(small, big));
			}
		}
		else
			min_order = MIN(min_order, visited[temp[i]]);
		i++;
	}
	return min_order;
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cin >> V >> E;
	int i = 0;
	while (i < E)
	{
		int a, b;
		std::cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
		i++;
	}
	dfs(1, 0);
	i = 0;
	int size = ans.size();
	std::cout << size << "\n";
	std::sort(ans.begin(), ans.end());
	while (i < size)
	{
		std::cout << ans[i].first << " " << ans[i].second << "\n";
		i++;
	}
}