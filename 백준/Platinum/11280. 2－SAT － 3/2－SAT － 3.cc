#include <iostream>
#include <vector>
#include <stack>
#include <cstring>

int N, M, idx;
std::vector < int > v[20002];
std::vector < int > r[20002];
std::vector < int > scc[20002];
std::stack < int > s;
int	visited[20002];

void	dfs_s(int x)
{
	visited[x] = idx;
	scc[idx].push_back(x);
	std::vector <int> temp = r[x];
	int i = 0;
	int size = temp.size();
	while (i < size)
	{
		if (visited[temp[i]] == 0)
			dfs_s(temp[i]);
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
	std::cin >> N >> M;
	int i = 0;
	while (i < M)
	{
		int a, b;
		std::cin >> a >> b;
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
	std::cout << flag << "\n";
}