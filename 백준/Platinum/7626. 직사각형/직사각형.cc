#include <iostream>
#include <algorithm>
#include <vector>

int N, max;
typedef long long ll;
typedef struct s_data
{
	int x;
	int y1;
	int y2;
	bool	isopen;
}	t_data;
std::vector < t_data > arr;
int comp_y[400010];
std::vector < std::pair <ll, ll> >	tree;
std::vector <int> v;
ll	ans;

int compare(t_data a, t_data b)
{
	if (a.x < b.x)
		return 1;
	return 0;
}

void tree_update(int s, int e, int node, int left, int right, bool isopen)
{
	if (left <= s && right >= e)
	{
		if (isopen)
			tree[node].second += 1;
		else
			tree[node].second -= 1;
	}
	else
	{
		int mid = (s + e) / 2;
		if (left <= mid)
			tree_update(s, mid, node * 2, left, right, isopen);
		if (right > mid)
			tree_update(mid + 1, e, node * 2 + 1, left, right, isopen);
	}
	if (tree[node].second > 0)
		tree[node].first = comp_y[e + 1] - comp_y[s];
	else
	{
		if (s == e)
			tree[node].first = 0;
		else
			tree[node].first = tree[node * 2].first + tree[node * 2 + 1].first;
	}
}

t_data	make_data(int x, int y1, int y2, bool isopen)
{
	t_data	temp;
	temp.x = x;
	temp.y1 = y1;
	temp.y2 = y2;
	temp.isopen = isopen;
	return temp;
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cin >> N;
	int i = 1;
	while (i <= N)
	{
		int x1, x2, y1, y2, a, b;
		std::cin >> x1 >> x2 >> y1 >> y2;
		arr.push_back(make_data(x1, y1, y2, 1));
		arr.push_back(make_data(x2, y1, y2, 0));
		v.push_back(y1);
		v.push_back(y2);
		i++;
	}
	std::sort(v.begin(), v.end());
	v.erase(std::unique(v.begin(), v.end()), v.end());
	i = 0;
	int size = arr.size();
	while (i < size)
	{
		if (i % 2 == 1)
		{
			arr[i].y1 = arr[i - 1].y1;
			arr[i].y2 = arr[i - 1].y2;
			i++;
			continue ;
		}
		int idx = std::lower_bound(v.begin(), v.end(), arr[i].y1) - v.begin();
		comp_y[idx] = arr[i].y1;
		arr[i].y1 = idx;
		idx = std::lower_bound(v.begin(), v.end(), arr[i].y2) - v.begin();
		comp_y[idx] = arr[i].y2;
		arr[i].y2 = idx;
		i++;
	}
	max = v.size() - 1;
	tree.resize(((max + 1) << 2) + 10, std::make_pair(0, 0));
	std::sort(arr.begin(), arr.end(), compare);
	i = 0;
	while (i < size)
	{
		if (i > 0)
			ans += (ll)tree[1].first * (arr[i].x - arr[i - 1].x);
		tree_update(0, max, 1, arr[i].y1, arr[i].y2 - 1, arr[i].isopen);
		i++;
	}
	std::cout << ans << "\n";
}
