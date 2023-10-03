#include <iostream>
#include <vector>
#include <stack>
#include <cstring>

int N, M, idx;
std::vector < int > v[2002];
std::vector < int > r[2002];
std::stack < int > s;
int	visited[2002];
int	indegree[2002];

void	dfs_s(int x)
{
	visited[x] = idx;
	std::vector <int> temp = r[x];
	int i = 0;
	int size = temp.size();
	while (i < size)
	{
		if (visited[temp[i]] == 0)
			dfs_s(temp[i]);
		else
			indegree[idx]++;
		i++;
	}
}

void	dfs_v(int x)
{
	visited[x] = 1;
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
	while (1)
	{
		std::memset(v, 0, sizeof(v));
		std::memset(r, 0, sizeof(r));
		std::memset(visited, 0, sizeof(visited));
		std::memset(indegree, 0, sizeof(indegree));
		std::cin >> N >> M;
		if (std::cin.eof())
			break ;
		int i = 0;
		while (i <= M)
		{
			int a, b;
			if (i != M)
				std::cin >> a >> b;
			else
			{
				a = 1;
				b = 1;
			}
			int a2 = abs(a), b2 = abs(b);
			v[(a2 << 1) - (a > 0)].push_back((b2 << 1) - (b < 0));
			v[(b2 << 1) - (b > 0)].push_back((a2 << 1) - (a < 0));
			r[(b2 << 1) - (b < 0)].push_back((a2 << 1) - (a > 0));
			r[(a2 << 1) - (a < 0)].push_back((b2 << 1) - (b > 0));
			i++;
		}
		i = 1;
		while (i <= (N << 1))
		{
			if (visited[i] == 0)
				dfs_v(i);
			i++;
		}
		std::memset(visited, 0, sizeof(visited));
		idx = 0;
		while (!s.empty())
		{
			int cur = s.top();
			s.pop();
			if (visited[cur] == 0)
			{
				idx++;
				dfs_s(cur);
			}
		}
		i = 1;
		int flag = 1;
		while (i < (N << 1))
		{
			if (visited[i] == visited[i + 1])
			{
				flag = 0;
				break ;
			}
			i += 2;
		}
		if (!flag)
		{
			std::cout << "no\n";
			continue ;
		}
		std::cout << "yes\n";
	}
}
