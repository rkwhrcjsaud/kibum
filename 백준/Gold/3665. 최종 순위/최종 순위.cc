#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

int T;

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cin >> T;
	while (T--)
	{
		int n;
		std::cin >> n;
		std::vector <int> v1;
		int	arr[n + 1][n + 1];
		int indegree[n + 1];
		std::memset(arr, 0, sizeof(arr));
		std::memset(indegree, 0, sizeof(indegree));
		int i = 0;
		while (i < n)
		{
			int temp;
			std::cin >> temp;
			int j = 0;
			int size = v1.size();
			while (j < size)
				arr[v1[j++]][temp] = 1;
			v1.push_back(temp);
			indegree[temp] = i;
			i++;
		}
		i = 0;
		int m;
		std::cin >> m;
		while (i < m)
		{
			int a, b;
			std::cin >> a >> b;
			if (arr[a][b] == 1)
			{
				arr[a][b] = 0;
				arr[b][a] = 1;
				indegree[a]++;
				indegree[b]--;
			}
			else
			{
				arr[a][b] = 1;
				arr[b][a] = 0;
				indegree[a]--;
				indegree[b]++;
			}
			i++;
		}
		std::queue <int> q;
		std::vector <int> ans;
		i = 1;
		while (i <= n)
		{
			if (indegree[i] == 0)
				q.push(i);
			i++;
		}
		while (!q.empty())
		{
			int j = 1;
			while (j <= n)
			{
				if (arr[q.front()][j])
				{
					indegree[j]--;
					if (indegree[j] == 0)
						q.push(j);
				}
				j++;
			}
			ans.push_back(q.front());
			q.pop();
		}
		i = 0;
		int size = ans.size();
		if (size != n)
			std::cout << "IMPOSSIBLE";
		else
			while (i < size)
				std::cout << ans[i++] << " ";
		std::cout << "\n";
	}
}