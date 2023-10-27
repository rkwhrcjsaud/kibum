#include <iostream>

int N, M, Q;
int tree[400004];
bool lazy[400004];

void	update_lazy(int s, int e, int node)
{
	if (lazy[node])
	{
		tree[node] = (e - s + 1) - tree[node];
		if (s != e)
		{
			lazy[node * 2] ^= lazy[node];
			lazy[node * 2 + 1] ^= lazy[node];
		}
		lazy[node] = false;
	}
}

void	seg_update(int s, int e, int node, int l, int r)
{
	update_lazy(s, e, node);
	if (s > r || e < l)
		return ;
	if (l <= s && e <= r)
	{
		tree[node] = (e - s + 1) - tree[node];
		if (s != e)
		{
			lazy[node * 2] ^= true;
			lazy[node * 2 + 1] ^= true;
		}
		return ;
	}
	int mid = (s + e) / 2;
	seg_update(s, mid, node * 2, l, r);
	seg_update(mid + 1, e, node * 2 + 1, l, r);
	if (s != e)
		tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

int seg_search(int s, int e, int node, int l, int r)
{
	update_lazy(s, e, node);
	if (s > r || e < l)
		return 0;
	if (l <= s && e <= r)
		return tree[node];
	int mid = (s + e) / 2;
	return (seg_search(s, mid, node * 2, l, r) + seg_search(mid + 1, e, node * 2 + 1, l, r));
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cin >> N >> M;
	int i = 1;
	while (i <= M)
	{
		std::cin >> Q;
		if (Q == 1)
		{
			int s, e;
			std::cin >> s >> e;
			std::cout << seg_search(1, N, 1, s, e) << "\n";
		}
		else
		{
			int s, e;
			std::cin >> s >> e;
			seg_update(1, N, 1, s, e);
		}
		i++;
	}
}
