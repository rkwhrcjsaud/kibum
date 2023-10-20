#include <iostream>
#include <vector>

int T, N, M;
bool arr[81][81];
std::vector <int> v[81 * 81];
bool visited[81 * 81];
int pos[81 * 81];
int p[2][6] = {{-1, -1, -1, 1, 1, 1}, {-1, 0, 1, -1, 0, 1}};

bool	dfs(int node)
{
	int i = 0;
	int size = v[node].size();
	while (i < size)
	{
		if (!visited[v[node][i]])
		{
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
	std::cin >> T;
	while (T--)
	{
		std::fill(pos, pos + 81 * 81, 0);
		int i = 0;
		while (i < 81 * 81)
			v[i++].clear();
		i = 0;
		while (i < 81)
		{
			int j = 0;
			while (j < 81)
				arr[i][j++] = false;
			i++;
		}
		std::cin >> N >> M;
		int student = 0;
		i = 0;
		while (i < N)
		{
			std::string str;
			std::cin >> str;
			int j = 0;
			while (j < M)
			{
				if (str[j] == '.')
				{
					student++;
					arr[i][j] = true;
				}
				j++;
			}
			i++;
		}
		i = 0;
		while (i < N)
		{
			int j = 0;
			while (j < M)
			{
				if (!arr[i][j])
				{
					j += 2;
					continue ;
				}
				int m = 0;
				while (m < 6)
				{
					int i_next = i + p[1][m];
					int j_next = j + p[0][m];
					if (arr[i_next][j_next])
						v[i * M + j + 1].push_back(i_next * M + j_next + 1);
					m++;
				}
				j += 2;
			}
			i++;
		}
		int cnt = 0;
		i = 1;
		while (i <= N * M)
		{
			std::fill(visited, visited + (81 * 81), 0);
			if (dfs(i))
				cnt++;
			i++;
		}
		std::cout << student - cnt << "\n";
	}
}