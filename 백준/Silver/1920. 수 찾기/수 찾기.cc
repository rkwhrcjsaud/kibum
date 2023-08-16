#include <iostream>
#include <algorithm>

int n, m;
int	A[100002];
int B[100002];

int	solve(int left, int right, int k)
{
	if (left > right)
		return 0;
	int mid = (right + left) / 2;
	if (A[mid] > k)
		return solve(left, mid - 1, k);
	else if (A[mid] < k)
		return solve(mid + 1, right, k);
	else if (A[mid] == k)
		return 1;
	return 0;
}

int	compare(int a, int b)
{
	return a < b;
}

int main(void)
{
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);
	std::cin >> n;
	int i = 0;
	while (i < n)
		std::cin >> A[i++];
	std::cin >> m;
	i = 0;
	while (i < m)
		std::cin >> B[i++];
	std::sort(A, A + n, compare);
	i = 0;
	while (i < m)
		std::cout << solve(0, n - 1, B[i++]) << "\n";
}