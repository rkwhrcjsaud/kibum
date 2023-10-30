#include <iostream>
#include <vector>

int N, M, Q;

class node
{
	public :
		int start;
		int end;
		std::vector <int> next;
};

node v[100001];
int tree[400004];
int lazy[400004];

int dfs(int x, int num)
{
	int i = 0;
	int size = v[x].next.size();
	v[x].start = num;
	while (i < size)
	{
		int next = v[x].next[i];
		num = dfs(next, num + 1);
		i++;
	}
	v[x].end = num;
	return num;
}

void	update_lazy(int s, int e, int node)
{
	if (lazy[node])
	{
		tree[node] = (e - s + 1) * (lazy[node] == 1);
		if (s != e)
		{
			lazy[node * 2] = lazy[node];
			lazy[node * 2 + 1] = lazy[node];
		}
		lazy[node] = 0;
	}
}

void	seg_update(int s, int e, int node, int l, int r, int k)
{
	if (s > e)
		return ;
	update_lazy(s, e, node);
	if (s > r || e < l)
		return ;
	if (l <= s && e <= r)
	{
		tree[node] = (e - s + 1) * (k == 1);
		if (s != e)
		{
			lazy[node * 2] = k;
			lazy[node * 2 + 1] = k;
		}
		lazy[node] = 0;
		return ;
	}
	int mid = (s + e) / 2;
	seg_update(s, mid, node * 2, l, r, k);
	seg_update(mid + 1, e, node * 2 + 1, l, r, k);
	if (s != e)
		tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

int seg_search(int s, int e, int node, int l, int r)
{
	if (s > e)
		return 0;
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
	std::cin >> N;
	int i = 1;
	while (i <= N)
	{
		int parent;
		std::cin >> parent;
		if (parent)
			v[parent].next.push_back(i);
		i++;
	}
	dfs(1, 1);
	seg_update(1, N, 1, 1, N, 1);
	std::cin >> M;
	i = 1;
	while (i <= M)
	{
		int emp;
		std::cin >> Q >> emp;
		if (Q == 1)
			seg_update(1, N, 1, v[emp].start + 1, v[emp].end, 1);
		else if (Q == 2)
			seg_update(1, N, 1, v[emp].start + 1, v[emp].end, 2);
		else
			std::cout << seg_search(1, N, 1, v[emp].start + 1, v[emp].end) << "\n";
		i++;
	}
}