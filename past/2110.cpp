#include <iostream>
#include <algorithm>

int n, c;
int arr[200002];

int solve(int left, int right)
{
	if (left > right)
		return right;
	int mid = (left + right) / 2;
	int i = 1;
	int temp = arr[0] + mid;
	int cnt = c - 1;
	while (i < n && cnt)
	{
		if (arr[i] >= temp)
		{
			cnt--;
			temp = arr[i] + mid;
		}
		i++;
	}
	if (cnt)
		return solve(left, mid - 1);
	return solve(mid + 1, right);
}

int compare(int a, int b)
{
	return a < b;
}

int main(void)
{
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);
	std::cin >> n >> c;
	int i = 0;
	while (i < n)
		std::cin >> arr[i++];
	std::sort(arr, arr + n, compare);
	std::cout << solve(0, 1000000000) << "\n";
}