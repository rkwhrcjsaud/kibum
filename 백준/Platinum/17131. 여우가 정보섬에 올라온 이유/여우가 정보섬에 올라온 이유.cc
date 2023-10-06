#include <iostream>
#include <algorithm>

int N;
typedef long long ll;
#define MAX(a, b) (a > b ? a : b)
#define MIN(a, b) (a < b ? a : b)
#define INF 400001
#define DIV 1000000007
std::pair <int, int> arr[200001];
int tree[INF << 2];
int ans, ans1, ans2;

void	tree_search(int s, int e, int node, int x)
{
	if (e < x)
	{
		ans1 += tree[node];
		ans1 %= DIV;
		return ;
	}
	if (s > x)
	{
		ans2 += tree[node];
		ans2 %= DIV;
		return ;
	}
	if (s == e)
		return ;
	int mid = (s + e) / 2;
	tree_search(s, mid, node * 2, x);
	tree_search(mid + 1, e, node * 2 + 1, x);
}

int tree_insert(int s, int e, int node, int x)
{
	if (e < x || x < s)
		return tree[node];
	if (s == e)
	{
		tree[node]++;
		tree[node] %= DIV;
		return tree[node];
	}
	int mid = (s + e) / 2;
	tree[node] = (tree_insert(s, mid, node * 2, x)
				+ tree_insert(mid + 1, e, node * 2 + 1, x)) % DIV;
	return (tree[node]);
}

int compare(std::pair <int, int> a, std::pair <int, int> b)
{
	if (a.second > b.second)
		return 1;
	else if (a.second < b.second)
		return 0;
	else
	{
		if (a.first < b.first)
			return 1;
		else
			return 0;
	}
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cin >> N;
	int i = 1;
	while (i <= N)
	{
		std::cin >> arr[i].first >> arr[i].second;
		arr[i].first += 200001;
		arr[i].second += 200001;
		i++;
	}
	i = 1;
	std::sort(arr + 1, arr + N + 1, compare);
	int temp_y = arr[1].second;
	int	temp_x = -1;
	int fixed = 0;
	int fixed2 = 0;
	while (i <= N)
	{
		ans1 = 0;
		ans2 = 0;
		tree_search(1, INF, 1, arr[i].first);
		if (temp_y != arr[i].second)
		{
			fixed = 0;
			temp_y = arr[i].second;
		}
		else if (temp_x == arr[i].first)
			fixed2++;
		if (temp_x != arr[i].first)
			fixed2 = 0;
		if (ans1 - (fixed - fixed2) < 0)
			ans1 += DIV;
		ans += ((ll)((ans1 - (fixed - fixed2)) % DIV) * (ll)(ans2 % DIV)) % DIV;
		ans %= DIV;
		tree_insert(1, INF, 1, arr[i].first);
		temp_x = arr[i].first;
		fixed++;
		i++;
	}
	std::cout << ans << "\n";
}
