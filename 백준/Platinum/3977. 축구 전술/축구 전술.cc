#include <iostream>
#include <vector>
#include <cstring>
#include <stack>
#include <algorithm>

int T;
std::vector <int> v[100001];
std::vector <int> r[100001];
std::vector <int> v2[100001];
std::vector <int> ans;
std::stack <int> s;
int visited[100001];
int indegree[100001];
int idx;

void	dfs_s(int x)
{
	v2[idx].push_back(x);
	visited[x] = idx;
	std::vector <int> temp = r[x];
	int i = 0;
	int size = temp.size();
	while (i < size)
	{
		if (visited[temp[i]] == 0)
		{
			dfs_s(temp[i]);
		}
		else if (visited[x] != visited[temp[i]])
			indegree[idx]++;
		i++;
	}
}

void	dfs_v(int x)
{
	visited[x] = true;
	int i = 0;
	std::vector <int> temp = v[x];
	int size = temp.size();
	while (i < size)
	{
		if (visited[temp[i]] == 0)
			dfs_v(temp[i]);
		i++;
	}
	s.push(x);
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cin >> T;
	while (T--)
	{
		int N, M;
		std::cin >> N >> M;
		std::memset(v, 0, sizeof(v));
		std::memset(r, 0, sizeof(r));
		std::memset(v2, 0, sizeof(v2));
		ans.clear();
		std::memset(visited, 0, sizeof(visited));
		std::memset(indegree, 0, sizeof(indegree));
		int i = 0;
		while (i < M)
		{
			int a, b;
			std::cin >> a >> b;
			v[a].push_back(b);
			r[b].push_back(a);
			i++;
		}
		i = 0;
		while (i < N)
		{
			if (visited[i] == 0)
				dfs_v(i);
			i++;
		}
		std::memset(visited, 0, sizeof(visited));
		idx = 1;
		int cnt = 0;
		while (!s.empty())
		{
			int cur = s.top();
			s.pop();
			if (visited[cur] == 0)
			{
				visited[cur] = idx;
				dfs_s(cur);
				idx++;
			}
		}
		i = 1;
		int flag = 0;
		while (i < idx)
		{
			if (indegree[i] == 0)
			{
				if (flag)
				{
					flag = 2;
					break ;
				}
				flag = 1;
				int j = 0;
				int size = v2[i].size();
				while (j < size)
				{
					ans.push_back(v2[i][j]);
					j++;
				}
			}
			i++;
		}
		i = 0;
		int size = ans.size();
		std::sort(ans.begin(), ans.end());
		if (flag == 2)
			std::cout << "Confused\n";
		else
			while (i < size)
				std::cout << ans[i++] << "\n";
		std::cout << "\n";
	}
}