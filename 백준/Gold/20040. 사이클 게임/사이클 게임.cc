#include <iostream>

int N, M;
int parent[500002];

int find_root(int x)
{
	if (x != parent[x])
		return (parent[x] = find_root(parent[x]));
	return (parent[x]);
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cin >> N >> M;
	int i = 1;
	while (i <= N)
	{
		parent[i] = i;
		i++;
	}
	i = 0;
	int flag = 0;
	int cnt = 0;
	while (i < M)
	{
		int a, b;
		std::cin >> a >> b;
		if (flag)
		{
			i++;
			continue ;
		}
		int root_a = find_root(a);
		int root_b = find_root(b);
		if (root_a == root_b)
			flag = 1;
		else
			parent[root_b] = root_a;
		cnt++;
		i++;
	}
	if (flag == 0)
		cnt = 0;
	std::cout << cnt << "\n";
}