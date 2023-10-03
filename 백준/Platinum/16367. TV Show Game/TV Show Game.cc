#include <iostream>
#include <vector>
#include <stack>
#include <cstring>

int K, N, idx;
std::vector < int > v[10001];
std::vector < int > r[10001];
std::vector < int > scc[10001];
std::stack < int > s;
int	visited[10001];

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

void	insert(int a, char ac, int b, char bc)
{
	v[(a << 1) - (ac == 'R')].push_back((b << 1) - (bc == 'B'));
	v[(b << 1) - (bc == 'R')].push_back((a << 1) - (ac == 'B'));
	r[(b << 1) - (bc == 'B')].push_back((a << 1) - (ac == 'R'));
	r[(a << 1) - (ac == 'B')].push_back((b << 1) - (bc == 'R'));
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cin >> K >> N;
	int i = 0;
	while (i < N)
	{
		int a, b, c;
		char ac, bc, cc;
		std::cin >> a >> ac >> b >> bc >> c >> cc;
		int j = 0;
		insert(a, ac, b, bc);
		insert(b, bc, c, cc);
		insert(a, ac, c, cc);
		i++;
	}
	i = 1;
	while (i <= (K << 1))
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
	while (i < (K << 1))
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
		std::cout << "-1\n";
		return (0);
	}
	i = 1;
	while (i < (K << 1))
	{
		if (visited[i] < visited[i + 1])
			std::cout << "R";
		else
			std::cout << "B";
		i += 2;
	}
	std::cout << "\n";
}

