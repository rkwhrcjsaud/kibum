#include <iostream>
#include <vector>
#include <algorithm>

int N, ans;
#define MAX(a, b) (a > b ? a : b)

class Square
{
	public :
		int y1;
		int y2;
};

std::vector <Square> v;
std::vector <int> temp_v;
std::vector <int> line[200002];
int tree[800008];
int lazy[800008];
int end_square[200002];

int compare(Square a, Square b)
{
	if (a.y1 < b.y1)
		return 1;
	return 0;
}

void	update_lazy(int s, int e, int node)
{
	if (lazy[node])
	{
		tree[node] += lazy[node];
		if (s != e)
		{
			lazy[node * 2] += lazy[node];
			lazy[node * 2 + 1] += lazy[node];
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
		tree[node] += k;
		if (s != e)
		{
			lazy[node * 2] += k;
			lazy[node * 2 + 1] += k;
		}
		return ;
	}
	int mid = (s + e) / 2;
	seg_update(s, mid, node * 2, l, r, k);
	seg_update(mid + 1, e, node * 2 + 1, l, r, k);
	if (s != e)
		tree[node] = MAX(tree[node * 2], tree[node * 2 + 1]);
}

int seg_search(int s, int e, int node, int l, int r)
{
	update_lazy(s, e, node);
	if (s > r || e < l)
		return 0;
	if (l <= s && e <= r)
		return tree[node];
	int mid = (s + e) / 2;
	return (MAX(seg_search(s, mid, node * 2, l, r), seg_search(mid + 1, e, node * 2 + 1, l, r)));
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cin >> N;
	int i = 1;
	while (i <= N)
	{
		Square temp;
		std::cin >> temp.y2 >> temp.y2 >> temp.y1 >> temp.y1;
		v.push_back(temp);
		temp_v.push_back(temp.y1);
		temp_v.push_back(temp.y2);
		i++;
	}
	std::sort(v.begin(), v.end(), compare);
	std::sort(temp_v.begin(), temp_v.end());
	temp_v.erase(std::unique(temp_v.begin(), temp_v.end()), temp_v.end());
	i = 0;
	while (i < N)
	{
		v[i].y1 = std::lower_bound(temp_v.begin(), temp_v.end(), v[i].y1) - temp_v.begin();
		v[i].y2 = std::lower_bound(temp_v.begin(), temp_v.end(), v[i].y2) - temp_v.begin();
		seg_update(0, 2 * N, 1, v[i].y1, v[i].y2, 1);
		line[v[i].y1].push_back(v[i].y2);
		end_square[v[i].y2 + 1]++;
		i++;
	}
	i = 0;
	ans = seg_search(0, 2 * N, 1, 0, 2 * N);
	int cnt = 0;
	while (i < 2 * N)
	{
		int j = 0;
		int size = line[i].size();
		while (j < size)
			seg_update(0, 2 * N, 1, i, line[i][j++], -1);
		cnt += j - end_square[i];
		ans = MAX(ans, cnt + seg_search(0, 2 * N, 1, 0, 2 * N));
		i++;
	}
	std::cout << ans << "\n";
}