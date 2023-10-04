#include <iostream>

int N;
int	tree[8000004];

void	tree_insert(int s, int e, int node, int idx)
{
	if (s > idx || idx > e)
		return ;
	tree[node]++;
	if (s == e)
		return ;
	int mid = (s + e) / 2;
	tree_insert(s, mid, node * 2, idx);
	tree_insert(mid + 1, e, node * 2 + 1, idx);
}

void	tree_eraser(int s, int e, int node, int rank)
{
	int mid = (s + e) / 2;
	if (s == e)
	{
		tree[node]--;
		std::cout << s << "\n";
		return ;
	}
	if (tree[node * 2] < rank)
	{
		tree[node]--;
		tree_eraser(mid + 1, e, node * 2 + 1, rank - tree[node * 2]);
	}
	else
	{
		tree[node]--;
		tree_eraser(s, mid, node * 2, rank);
	}
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cin >> N;
	int i = 0;
	while (i < N)
	{
		int a, b;
		std::cin >> a >> b;
		if (a == 1)
			tree_insert(1, 2000000, 1, b);
		else if (a == 2)
			tree_eraser(1, 2000000, 1, b);
		i++;
	}
}