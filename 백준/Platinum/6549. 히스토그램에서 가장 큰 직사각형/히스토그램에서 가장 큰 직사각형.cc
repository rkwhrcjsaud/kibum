#include <iostream>
#include <vector>
#define LIMIT 1000000002
#define MAX(a, b) (a > b ? a : b)

std::vector<int> a(100002);
std::vector<int> v(400002);
unsigned long long int	ans;

int init(std::vector<int> &arr, std::vector<int> &tree, int node, int start, int end)
{
	if (start == end)
		return (tree[node] = start);
	int mid = (start + end) / 2;
	int leftIdx = init(arr, tree, node * 2, start, mid);
	int rightIdx = init(arr, tree, node * 2 + 1, mid + 1, end);
	if (arr[leftIdx] <= arr[rightIdx])
		tree[node] = leftIdx;
	else
		tree[node] = rightIdx;
	return (tree[node]);
}

int	query(int node, int start, int end, int left, int right)
{
	if (end < left || right < start)
		return (LIMIT);
	if (left <= start && end <= right)
		return (v[node]);
	int mid = (start + end) / 2;
	int leftIdx = query(2 * node, start, mid, left, right);
	int rightIdx = query(2 * node + 1, mid + 1, end, left, right);
	
	if (leftIdx == LIMIT)
		return rightIdx;
	if (rightIdx == LIMIT)
		return leftIdx;
	return a[leftIdx] < a[rightIdx] ? leftIdx : rightIdx;
}

void	solve(int left, int right, int n)
{
	if (left > right)
		return ;
	int mid = query(1, 1, n, left, right);

	ans = MAX(ans, (unsigned long long int)a[mid] * (right - left + 1));
	solve(left, mid - 1, n);
	solve(mid + 1, right, n);
}

int main(void)
{
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);
	int n;
	std::cin >> n;
	while (n)
	{
		int i = 1;
		ans = 0;
		while (i <= n)
			std::cin >> a[i++];
		init(a, v, 1, 1, n);
		solve(1, n, n);
		std::cout << ans << "\n";
		std::fill(v.begin(), v.end(), 0);
		std::fill(a.begin(), a.end(), 0);
		std::cin >> n;
	}
}
