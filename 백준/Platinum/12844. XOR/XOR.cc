#include <iostream>

int N, M, Q;
int arr[500001];
int tree[2000004];
int lazy[2000004];

void seg_init(int s, int e, int node)
{
	if (s == e)
	{
		tree[node] = arr[s];
		return ;
	}
	int mid = (s + e) / 2;
	seg_init(s, mid, node * 2);
	seg_init(mid + 1, e, node * 2 + 1);
	tree[node] = tree[node * 2] ^ tree[node * 2 + 1];
}

void	update_lazy(int s, int e, int node)
{
	if (lazy[node])
	{
		if ((e - s + 1) % 2 == 1)
			tree[node] ^= lazy[node];
		if (s != e)
		{
			lazy[node * 2] ^= lazy[node];
			lazy[node * 2 + 1] ^= lazy[node];
		}
		lazy[node] = 0;
	}
}

void	seg_update(int s, int e, int node, int l, int r, int k)
{
	update_lazy(s, e, node);
	if (s > r || e < l)
		return ;
	if (l <= s && e <= r)
	{
		if ((e - s + 1) % 2 == 1)
			tree[node] ^= k;
		if (s != e)
		{
			lazy[node * 2] ^= k;
			lazy[node * 2 + 1] ^= k;
		}
		return ;
	}
	int mid = (s + e) / 2;
	seg_update(s, mid, node * 2, l, r, k);
	seg_update(mid + 1, e, node * 2 + 1, l, r, k);
	if (s != e)
		tree[node] = tree[node * 2] ^ tree[node * 2 + 1];
}

int seg_search(int s, int e, int node, int l, int r)
{
	update_lazy(s, e, node);
	if (s > r || e < l)
		return 0;
	if (l <= s && e <= r)
		return tree[node];
	int mid = (s + e) / 2;
	return (seg_search(s, mid, node * 2, l, r) ^ seg_search(mid + 1, e, node * 2 + 1, l, r));
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cin >> N;
	int i = 0;
	while (i < N)
		std::cin >> arr[i++];
	std::cin >> M;
	seg_init(0, N - 1, 1);
	i = 1;
	while (i <= M)
	{
		std::cin >> Q;
		if (Q == 2)
		{
			int s, e;
			std::cin >> s >> e;
			std::cout << seg_search(0, N - 1, 1, s, e) << "\n";
		}
		else
		{
			int s, e, k;
			std::cin >> s >> e >> k;
			seg_update(0, N - 1, 1, s, e, k);
		}
		i++;
	}
}
