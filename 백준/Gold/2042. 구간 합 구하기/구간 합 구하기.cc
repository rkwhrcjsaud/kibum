#include <iostream>

typedef long long ll;
int N, M, K;
ll	arr[1000001];
ll	tree[4000004];

ll	make_tree(int s, int e, int node)
{
	if (s == e)
	{
		tree[node] = arr[s];
		return (tree[node]);
	}
	int mid = (s + e) / 2;
	tree[node] = make_tree(s, mid, node * 2) + make_tree(mid + 1, e, node * 2 + 1);
	return (tree[node]);
}

void	tree_change(int s, int e, int node, int idx, ll fixed)
{
	if (idx < s || idx > e)
		return ;
	tree[node] += fixed;
	if (s == e)
		return ;
	int mid = (s + e) / 2;
	tree_change(s, mid, node * 2, idx, fixed);
	tree_change(mid + 1, e, node * 2 + 1, idx, fixed);
}

ll	tree_sum(int s, int e, int node, int l, int r)
{
	if (l > e || r < s)
		return (0);
	if (l <= s && r >= e)
		return tree[node];
	int mid = (s + e) / 2;
	return (tree_sum(s, mid, node * 2, l, r) + tree_sum(mid + 1, e, node * 2 + 1, l, r));
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cin >> N >> M >> K;
	int i = 1;
	while (i <= N)
		std::cin >> arr[i++];
	make_tree(1, N, 1);
	i = 0;
	while (i < M + K)
	{
		ll a, b, c;
		std::cin >> a >> b >> c;
		if (a == 1)
		{
			ll fixed = c - arr[b];
			tree_change(1, N, 1, b, fixed);
			arr[b] = c;
		}
		else if (a == 2)
			std::cout << tree_sum(1, N, 1, b, c) << "\n";
		i++;
	}
}