#include <iostream>
#include <vector>

int N;

class Same
{
	public :
		int size;
		int speed;
		int smart;
		bool operator>=(const Same &other)
		{
			return (size >= other.size
				&& speed >= other.speed
				&& smart >= other.smart);
		}
		bool operator==(const Same &other)
		{
			return (size == other.size
				&& speed == other.speed
				&& smart == other.smart);
		}
};

Same same[52];
std::vector <int> v[52];
int		pos[52];
bool	visited[52];
bool	dead[52];

bool	dfs(int node)
{
	int i = 0;
	int size = v[node].size();
	while (i < size)
	{
		if (!visited[v[node][i]])
		{
			if (pos[v[node][i]] == node)
			{
				i++;
				continue ;
			}
			visited[v[node][i]] = true;
			if (pos[v[node][i]] == 0 || dfs(pos[v[node][i]]))
			{
				pos[v[node][i]] = node;
				return true;
			}
		}
		i++;
	}
	return false;
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cin >> N;
	int i = 0;
	while (++i <= N)
		std::cin >> same[i].size >> same[i].speed >> same[i].smart;
	i = 0;
	while (++i <= N)
	{
		int j = 0;
		while (++j <= N)
		{
			if (i == j || !(same[i] >= same[j]))
				continue ;
			if (same[i] == same[j] && i < j)
				continue ;
			v[i].push_back(j);
		}
	}
	int cnt = 0;
	i = 1;
	while (i <= N)
	{
		std::fill(visited, visited + 51, false);
		cnt += dfs(i);
		cnt += dfs(i);
		i++;
	}
	std::cout << N - cnt << "\n";
}