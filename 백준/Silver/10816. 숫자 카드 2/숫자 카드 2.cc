#include <iostream>
#include <algorithm>

int n, m;
int	arrA[500003], arrB[500003];

int	compare(int a, int b)
{
	return a < b;
}

int upperBound(int left, int right, int k)
{
	if (left > right)
		return 0;
	int mid = (right + left) / 2;
	if (arrA[mid] > k)
		return upperBound(left, mid - 1, k);
	if (arrA[mid] < k)
		return upperBound(mid + 1, right, k);
	if (arrA[mid] == k)
	{
		if (arrA[mid + 1] > k)
			return mid;
		return upperBound(mid + 1, right, k);
	}
	return 0;
}

int lowerBound(int left, int right, int k)
{
	if (left > right)
		return 0;
	int mid = (right + left) / 2;
	if (arrA[mid] > k)
		return lowerBound(left, mid - 1, k);
	if (arrA[mid] < k)
		return lowerBound(mid + 1, right, k);
	if (arrA[mid] == k)
	{
		if (arrA[mid - 1] < k)
			return mid - 1;
		return lowerBound(left, mid - 1, k);
	}
	return 0;
}

int	solve(int left, int right, int k)
{
	return upperBound(left, right, k) - lowerBound(left, right, k);
}

int main(void)
{
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);
	std::cin >> n;
	int i = 1;
	while (i <= n)
		std::cin >> arrA[i++];
	arrA[0] = -10000001;
	arrA[n + 1] = 10000001; 
	std::cin >> m;
	i = 0;
	while (i < m)
		std::cin >> arrB[i++];
	std::sort(arrA, arrA + n + 2, compare);
	i = 0;
	while (i < m)
		std::cout << solve(0, n + 2, arrB[i++]) << " ";
	std::cout << "\n";
}