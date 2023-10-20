#include <iostream>
#include <vector>
#include <stack>

int N, P;
std::vector <int> v[401];
int c[401][401];
int f[401][401];

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cin >> N >> P;
	int i = 0;
	while (i < P)
	{
		int a, b;
		std::cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
		c[a][b] = 1;
		c[b][a] = -1;
		i++;
	}
	int cnt = 0;
	while (1)
	{
		int prev[N + 1];
		std::fill(prev, prev + N + 1, -1);
		std::stack < int > q;
		q.push(1);
		while (!q.empty())
		{
			int curr = q.top();
			q.pop();
			i = 0;
			int size = v[curr].size();
			while (i < size)
			{
				int next = v[curr][i];
				if (prev[next] == -1 && c[curr][next] > f[curr][next])
				{
					q.push(next);
					prev[next] = curr;
					if (next == 2)
						break ;
				}
				i++;
			}
		}
		if (prev[2] == -1)
			break ;
		i = 2;
		while (i != 1)
		{
			f[prev[i]][i]++;
			f[i][prev[i]]--;
			i = prev[i];
		}
		cnt++;
	}
	std::cout << cnt << "\n";
}