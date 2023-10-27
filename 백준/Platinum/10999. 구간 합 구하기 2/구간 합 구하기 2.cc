#include <iostream>

typedef long long ll;
int N, M, K, Q;
ll arr[1000001];
ll tree[4000004];
ll lazy[4000004];

ll seg_init(int s, int e, int node)
{
	if (s == e)
		return tree[node] = arr[s];
	int mid = (s + e) / 2;
	return tree[node] = seg_init(s, mid, node * 2) + seg_init(mid + 1, e, node * 2 + 1);
}

void update_lazy(int node, int s, int e)
{
	if (lazy[node])
	{
		tree[node] += (e - s + 1) * lazy[node];
		if (s != e)
		{
			lazy[node * 2] += lazy[node];
			lazy[node * 2 + 1] += lazy[node];
		}
		lazy[node] = 0;
	}
}

void seg_sum(int s, int e, int node, int ss, int ee, ll w)
{
	update_lazy(node, s, e);
	if (ss > e || ee < s)
		return ;
	if (ss <= s && e <= ee)
	{
		tree[node] += (e - s + 1) * w;
		if (s != e)
		{
			lazy[node * 2] += w;
			lazy[node * 2 + 1] += w;
		}
		return ;
	}
	int mid = (s + e) / 2;
	seg_sum(s, mid, node * 2, ss, ee, w);
	seg_sum(mid + 1, e, node * 2 + 1, ss, ee, w);
	if (s != e)
		tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

ll seg_search(int s, int e, int node, int ss, int ee)
{
	update_lazy(node, s, e);
	if (ss > e || ee < s)
		return 0;
	if (s >= ss && ee >= e)
		return tree[node];
	int mid = (s + e) / 2;
	return (seg_search(s, mid, node * 2, ss, ee) + seg_search(mid + 1, e, node * 2 + 1, ss, ee));
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cin >> N >> M >> K;
	int i = 1;
	while (i <= N)
		std::cin >> arr[i++];
	seg_init(1, N, 1);
	i = 1;
	while (i <= M + K)
	{
		std::cin >> Q;
		if (Q == 1)
		{
			int s, e;
			ll w;
			std::cin >> s >> e >> w;
			seg_sum(1, N, 1, s, e, w);
		}
		else
		{
			int s, e;
			std::cin >> s >> e;
			std::cout << seg_search(1, N, 1, s, e) << "\n";
		}
		i++;
	}
}