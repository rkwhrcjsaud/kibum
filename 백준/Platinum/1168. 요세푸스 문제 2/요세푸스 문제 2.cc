#include <iostream>

int N, K;
int	tree[400004];

void	make_tree(int s, int e, int node)
{
	tree[node] += e - s + 1;
	if (s == e)
		return ;
	int mid = (s + e) / 2;
	make_tree(s, mid, node * 2);
	make_tree(mid + 1, e, node * 2 + 1);
}

void	tree_eraser(int s, int e, int node, int rank)
{
	int mid = (s + e) / 2;
	if (s == e)
	{
		tree[node]--;
		std::cout << s;
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
	std::cin >> N >> K;
	make_tree(1, N, 1);
	int rank = K;
	int num = N;
	std::cout << "<";
	while (1)
	{
		tree_eraser(1, N, 1, rank);
		num--;
		if (num == 0)
			break ;
		rank += K - 1;
		while (rank > num)
			rank -= num;
		if (rank == 0)
			rank = 1;
		std::cout << ", ";
	}
	std::cout << ">\n";
}