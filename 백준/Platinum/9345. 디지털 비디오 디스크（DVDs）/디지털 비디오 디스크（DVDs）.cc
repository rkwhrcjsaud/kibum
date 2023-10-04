#include <iostream>
#include <cstring>

#define MAX(a, b) (a > b ? a : b)
#define MIN(a, b) (a < b ? a : b)
typedef long long ll;
int T, N, K;
int	arr[100001];
std::pair <int, int>	tree[400004];

std::pair <int, int>	make_tree(int s, int e, int node)
{
	if (s == e)
	{
		tree[node].first = arr[s];
		tree[node].second = arr[s];
		return tree[node];
	}
	int mid = (s + e) / 2;
	std::pair <int, int> temp1 = make_tree(s, mid, node * 2);
	std::pair <int, int> temp2 = make_tree(mid + 1, e, node * 2 + 1);
	tree[node].first = MIN(temp1.first, temp2.first);
	tree[node].second = MAX(temp1.second, temp2.second);
	return (tree[node]);
}

std::pair <int, int>	tree_change(int s, int e, int node, int idx1, int idx2)
{
	if ((idx1 < s || idx1 > e) && (idx2 < s || idx2 > e))
		return tree[node];
	if (s == e)
	{
		if (s == idx1)
		{
			tree[node].first = arr[idx2];
			tree[node].second = arr[idx2];
		}
		if (s == idx2)
		{
			tree[node].first = arr[idx1];
			tree[node].second = arr[idx1];
		}
		return tree[node];
	}
	int mid = (s + e) / 2;
	std::pair <int, int> temp1 = tree_change(s, mid, node * 2, idx1, idx2);
	std::pair <int, int> temp2 = tree_change(mid + 1, e, node * 2 + 1, idx1, idx2);
	tree[node].first = MIN(temp1.first, temp2.first);
	tree[node].second = MAX(temp1.second, temp2.second);
	return (tree[node]);
}

bool	tree_check(int s, int e, int node, int left, int right)
{
	if (right < s || left > e)
		return 0;
	if (left <= s && right >= e)
	{
		if (tree[node].first < left || tree[node].second > right)
			return 1;
		else
			return 0;
	}
	int mid = (s + e) / 2;
	return (tree_check(s, mid, node * 2, left, right)
		|| tree_check(mid + 1, e, node * 2 + 1, left, right));
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cin >> T;
	while (T--)
	{
		std::memset(tree, 0, sizeof(tree));
		std::cin >> N >> K;
		int i = 0;
		while (i < N)
		{
			arr[i] = i;
			i++;
		}
		make_tree(0, N - 1, 1);
		i = 0;
		while (i < K)
		{
			int a, b, c;
			std::cin >> a >> b >> c;
			if (a == 0)
			{
				tree_change(0, N - 1, 1, b, c);
				int temp = arr[b];
				arr[b] = arr[c];
				arr[c] = temp;
			}
			else if (a == 1)
			{
				if (!tree_check(0, N - 1, 1, b, c))
					std::cout << "YES\n";
				else
					std::cout << "NO\n";
			}
			i++;
		}
	}
}
