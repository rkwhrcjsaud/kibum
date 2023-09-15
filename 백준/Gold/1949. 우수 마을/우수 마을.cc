#include <iostream>
#include <vector>
#include <algorithm>

#define MAX(a, b) (a > b ? a : b)

int N;
int w[10002];
int dp[10002][2];
std::vector < int > v[10002];
int visited[10002];

void	dfs(int x)
{
	visited[x] = true;
	dp[x][0] = 0;
	dp[x][1] = w[x];
	int i = 0;
	int size = v[x].size();
	while (i < size)
	{
		int next = v[x][i];
		if (visited[next] == false)
		{
			dfs(next);
			dp[x][0] += MAX(dp[next][0], dp[next][1]);
			dp[x][1] += dp[next][0];
		}
		i++;
	}
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cin >> N;
	int i = 1;
	while (i <= N)
		std::cin >> w[i++];
	i = 1;
	while (i < N)
	{
		int a, b;
		std::cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
		i++;
	}
	dfs(1);
	std::cout << MAX(dp[1][0], dp[1][1]) << "\n";
}
