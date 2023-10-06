#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

int T, N;
typedef long long ll;
#define MAX(a, b) (a > b ? a : b)
std::vector < int > v;
std::pair <ll, ll> arr[75005];
ll tree[300010];
ll max, ans;

int compare(std::pair <ll, ll> a, std::pair <ll, ll> b)
{
	if (a.first < b.first)
		return 1;
	else if (a.first > b.first)
		return 0;
	else
	{
		if (a.second > b.second)
			return 1;
		else
			return 0;
	}
}

void	tree_search(int s, int e, int node, int y)
{
	if (e < y)
		return ;
	if (s >= y)
	{
		ans += tree[node];
		return ;
	}
	int mid = (s + e) / 2;
	tree_search(s, mid, node * 2, y);
	tree_search(mid + 1, e, node * 2 + 1, y);
}

int tree_insert(int s, int e, int node, int y)
{
	if (e < y || y < s)
		return tree[node];
	if (s == e)
	{
		tree[node]++;
		return tree[node];
	}
	int mid = (s + e) / 2;
	tree[node] = tree_insert(s, mid, node * 2, y)
				+ tree_insert(mid + 1, e, node * 2 + 1, y);
	return (tree[node]);
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cin >> T;
	while (T--)
	{
		v.clear();
		std::memset(arr, 0, sizeof(arr));
		std::memset(tree, 0, sizeof(tree));
		std::cin >> N;
		int i = 1;
		while (i <= N)
		{
			std::cin >> arr[i].first >> arr[i].second;
			v.push_back(arr[i].second);
			i++;
		}
		std::sort(v.begin(), v.end());
		v.erase(std::unique(v.begin(), v.end()), v.end());
		i = 1;
		max = 0;
		while (i <= N)
		{
			int idx = std::lower_bound(v.begin(), v.end(), arr[i].second) - v.begin();
			arr[i].second = idx;
			max = MAX(idx, max);
			i++;
		}
		std::sort(arr + 1, arr + N + 1, compare);
		i = 1;
		ans = 0;
		while (i <= N)
		{
			tree_search(0, max, 1, arr[i].second);
			tree_insert(0, max, 1, arr[i].second);
			i++;
		}
		std::cout << ans << "\n";
	}
}