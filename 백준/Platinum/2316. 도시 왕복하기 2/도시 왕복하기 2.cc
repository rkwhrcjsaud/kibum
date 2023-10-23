#include <iostream>
#include <vector>
#include <stack>

int N, P;
std::vector <int> v[802];
int c[802][802];
int f[802][802];

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
		int a_in = a * 2;
		int a_out = a * 2 + 1;
		if (a == 1 || a == 2)
		{
			a_in = a;
			a_out = a;
		}
		int b_in = b * 2;
		int b_out = b * 2 + 1;
		if (b == 1 || b == 2)
		{
			b_in = b;
			b_out = b;
		}
		v[a_out].push_back(b_in);
		v[b_in].push_back(a_out);
		v[b_out].push_back(a_in);
		v[a_in].push_back(b_out);
		c[a_out][b_in] = 1;
		c[b_out][a_in] = 1;
		i++;
	}
	i = 3;
	while (i <= N)
	{
		v[i * 2].push_back(i * 2 + 1);
		v[i * 2 + 1].push_back(i * 2);
		c[i * 2][i * 2 + 1] = 1;
		i++;
	}
	int cnt = 0;
	while (1)
	{
		int prev[802];
		std::fill(prev, prev + 802, -1);
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