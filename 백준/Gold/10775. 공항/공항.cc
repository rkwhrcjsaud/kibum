#include <iostream>

int parent[100010];

int find(int x)
{
	if (parent[x] == x)
		return x;
	return parent[x] = find(parent[x]);
}

void merge(int x, int y)
{
	x = find(x);
	y = find(y);
	if (x == y)
		return ;
	if (x > y)
		parent[x] = y;
	else
		parent[y] = x;
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	int G, P;
	std::cin >> G >> P;
	int ans = 0;
	bool flag = false;
	for (int i = 1; i <= G; i++)
		parent[i] = i;
	for (int i = 0; i < P; i++)
	{
		int tmp;
		std::cin >> tmp;
		if (flag)
			continue;
		int root = find(tmp);
		if (root == 0)
		{
			flag = true;
			continue ;
		}
		merge(root, root - 1);
		ans++;
	}
	std::cout << ans << '\n';
}
