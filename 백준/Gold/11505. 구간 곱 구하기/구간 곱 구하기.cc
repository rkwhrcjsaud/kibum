#include <iostream>

#define DIV 1000000007
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
	tree[node] = (make_tree(s, mid, node * 2) * make_tree(mid + 1, e, node * 2 + 1)) % DIV;
	return (tree[node]);
}

ll	tree_change(int s, int e, int node, int idx, ll fixed)
{
	if (idx < s || idx > e)
		return tree[node];
	if (s == e && s == idx)
		return tree[node] = fixed;
	if (s == e)
		return tree[node];
	int mid = (s + e) / 2;
	return tree[node] = (tree_change(s, mid, node * 2, idx, fixed)
					* tree_change(mid + 1, e, node * 2 + 1, idx, fixed))
					% DIV;
}

ll	tree_mul(int s, int e, int node, int l, int r)
{
	if (l > e || r < s)
		return (1);
	if (l <= s && r >= e)
		return tree[node];
	int mid = (s + e) / 2;
	return ((tree_mul(s, mid, node * 2, l, r) * tree_mul(mid + 1, e, node * 2 + 1, l, r))
			% DIV);
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
			tree_change(1, N, 1, b, c);
			arr[b] = c;
		}
		else if (a == 2)
			std::cout << tree_mul(1, N, 1, b, c) << "\n";
		i++;
	}
}
