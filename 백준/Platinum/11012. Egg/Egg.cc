#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

int T;
typedef long long ll;
typedef struct s_data
{
	int x;
	int y1;
	int y2;
	bool	isopen;
}	t_data;

ll ans;
std::vector < t_data > v;
std::vector < std::pair <int, int> > nv;
int tree[400004];

t_data	make_data(int x, int y1, int y2, bool isopen)
{
	t_data	temp;
	temp.x = x;
	temp.y1 = y1;
	temp.y2 = y2;
	temp.isopen = isopen;
	return temp;
}

void tree_update(int s, int e, int node, int left, int right, bool isopen)
{
	if (left <= s && right >= e)
	{
		if (isopen)
			tree[node] += 1;
		else
			tree[node] -= 1;
	}
	else
	{
		int mid = (s + e) / 2;
		if (left <= mid)
			tree_update(s, mid, node * 2, left, right, isopen);
		if (right > mid)
			tree_update(mid + 1, e, node * 2 + 1, left, right, isopen);
	}
}

int compare(t_data a, t_data b)
{
	if (a.x < b.x)
		return 1;
	else if (a.x == b.x)
		return (a.isopen > b.isopen);
	return 0;
}

void	tree_check(int s, int e, int node, int y)
{
	if (s > y || e < y)
		return ;
	if (tree[node] > 0)
	{
		ans += tree[node];
	}
	if (s == e)
		return ;
	int mid = (s + e) / 2;
	tree_check(s, mid, node * 2, y);
	tree_check(mid + 1, e, node * 2 + 1, y);
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cin >> T;
	while (T--)
	{
		ans = 0;
		v.clear();
		nv.clear();
		std::memset(tree, 0, sizeof(tree));
		int n, m;
		std::cin >> n >> m;
		int i = 0;
		while (i < n)
		{
			int x, y;
			std::cin >> x >> y;
			nv.push_back(std::make_pair(x, y));
			i++;
		}
		std::sort(nv.begin(), nv.end());
		i = 0;
		while (i < m)
		{
			int x1, x2, y1, y2;
			std::cin >> x1 >> x2 >> y1 >> y2;
			v.push_back(make_data(x1, y1, y2, 1));
			v.push_back(make_data(x2 + 1, y1, y2, 0));
			i++;
		}
		std::sort(v.begin(), v.end(), compare);
		i = 0;
		int j = 0;
		int k = 0;
		int size = nv.size();
		while (i < (m << 1))
		{
			int temp = v[i].x;
			while (i < (m << 1) && v[i].x == temp)
			{
				tree_update(0, 100001, 1, v[i].y1, v[i].y2, v[i].isopen);
				i++;
			}
			while (j < size && nv[j].first < v[i].x)
			{
				tree_check(0, 100001, 1, nv[j].second);
				j++;
			}
		}
		std::cout << ans << "\n";
	}
}