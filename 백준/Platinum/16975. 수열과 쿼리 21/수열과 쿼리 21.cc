#include <iostream>

typedef long long ll;
int N, M;
int	arr[100001];
ll	tree[400004];

void	make_tree(int s, int e, int node)
{
	if (s == e)
	{
		tree[node] = arr[s];
		return ;
	}
	int mid = (s + e) / 2;
	make_tree(s, mid, node * 2);
	make_tree(mid + 1, e, node * 2 + 1);
}

void	tree_change(int s, int e, int node, int left, int right, int fixed)
{
	if (right < s || left > e)
		return ;
	if (s >= left && e <= right)
	{
		tree[node] += fixed;
		return ;
	}
	int mid = (s + e) / 2;
	tree_change(s, mid, node * 2, left, right, fixed);
	tree_change(mid + 1, e, node * 2 + 1, left, right, fixed);
}

void	tree_print(int s, int e, int node, int idx, ll ans)
{
	if (idx < s || idx > e)
		return ;
	if (s == e)
	{
		std::cout << ans + tree[node] << "\n";
		return ;
	}
	int mid = (s + e) / 2;
	tree_print(s, mid, node * 2, idx, ans + tree[node]);
	tree_print(mid + 1, e, node * 2 + 1, idx, ans + tree[node]);
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cin >> N;
	int i = 1;
	while (i <= N)
		std::cin >> arr[i++];
	make_tree(1, N, 1);
	i = 0;
	std::cin >> M;
	while (i < M)
	{
		int a;
		std::cin >> a;
		if (a == 1)
		{
			int b, c, d;
			std::cin >> b >> c >> d;
			tree_change(1, N, 1, b, c, d);
		}
		else if (a == 2)
		{
			int idx;
			std::cin >> idx;
			tree_print(1, N, 1, idx, 0);
		}
		i++;
	}
}