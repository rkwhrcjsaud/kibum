#include <iostream>
#include <vector>
#include <stack>
#include <cstring>

#define MAX(a, b) (a > b ? a : b)

int N, M, S, P, idx, ans;
std::vector < int > v[500001];
std::vector < int > r[500001];
std::vector < int > scc[500001];
bool	restaurant[500001];
std::stack < int > s;
int	cash[500001];
int	scc_cash[500001];
int visited[500001];
int	dp[500001];
bool	have_restaurant[500001];

void	dfs_s(int x)
{
	visited[x] = idx;
	scc_cash[idx] += cash[x];
	if (restaurant[x])
		have_restaurant[idx] = true;
	std::vector <int> temp = r[x];
	int i = 0;
	int size = temp.size();
	while (i < size)
	{
		if (visited[temp[i]] == 0)
			dfs_s(temp[i]);
		else if (visited[x] != visited[temp[i]])
			scc[visited[temp[i]]].push_back(idx);
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

int	dfs(int x)
{
	int i = 0;
	int size = scc[x].size();
	if (dp[x] != 0)
		return dp[x];
	while (i < size)
	{
		dp[x] = MAX(dp[x], dfs(scc[x][i]));
		i++;
	}
	if (dp[x] == 0)
	{
		if (have_restaurant[x])
			return dp[x] = scc_cash[x];
		else
			return dp[x] = 0;
	}
	else
		return dp[x] += scc_cash[x];
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
		v[a].push_back(b);
		r[b].push_back(a);
		i++;
	}
	i = 1;
	while (i <= N)
		std::cin >> cash[i++];
	std::cin >> S >> P;
	i = 0;
	while (i++ < P)
	{
		int temp;
		std::cin >> temp;
		restaurant[temp] = true;
	}
	i = 1;
	while (i <= N)
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
	std::cout << dfs(visited[S]) << "\n";
}