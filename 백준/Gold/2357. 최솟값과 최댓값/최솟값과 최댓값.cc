#include <iostream>

#define MAX(a, b) (a > b ? a : b)
#define MIN(a, b) (a < b ? a : b)
#define INF 1000000001
typedef long long ll;
int N, M;
ll arr[100001];
std::pair < ll, ll > tree[400004];

std::pair <ll, ll>	make_tree(int s, int e, int node)
{
	if (s == e)
	{
		tree[node].first = arr[s];
		tree[node].second = arr[s];
		return (tree[node]);
	}
	int mid = (s + e) / 2;
	std::pair <ll, ll> temp1 = make_tree(s, mid, node * 2);
	std::pair <ll, ll> temp2 = make_tree(mid + 1, e, node * 2 + 1);
	tree[node].first = MIN(temp1.first, temp2.first);
	tree[node].second = MAX(temp1.second, temp2.second);
	return (tree[node]);
}

std::pair <ll, ll>	tree_check(int s, int e, int node, int l, int r)
{
	if (l > e || r < s)
		return (std::make_pair(INF, 0));
	if (l <= s && r >= e)
		return (tree[node]);
	int mid = (s + e) / 2;
	std::pair <ll, ll> temp1 = tree_check(s, mid, node * 2, l, r);
	std::pair <ll, ll> temp2 = tree_check(mid + 1, e, node * 2 + 1, l, r);
	std::pair <ll, ll> temp;
	temp.first = MIN(temp1.first, temp2.first);
	temp.second = MAX(temp1.second, temp2.second);
	return (temp);
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cin >> N >> M;
	int i = 1;
	while (i <= N)
		std::cin >> arr[i++];
	make_tree(1, N, 1);
	i = 0;
	while (i < M)
	{
		int a, b;
		std::cin >> a >> b;
		std::pair <ll, ll> ans = tree_check(1, N, 1, a, b);
		std::cout << ans.first << " " << ans.second << "\n";
		i++;
	}
}