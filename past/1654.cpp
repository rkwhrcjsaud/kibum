#include <iostream>

typedef unsigned long long int ull;

int k, n;
int	arr[10002];
#define MAX 2147483647

int solve(ull left, ull right)
{
	if (left > right)
		return right;
	int i = 0;
	ull cnt = 0;
	ull mid = (left + right) / 2;
	while (i < k)
		cnt += arr[i++] / mid;
	if (cnt >= n)
		return solve(mid + 1, right);
	else if (cnt < n)
		return solve(left, mid - 1);
	return (0);
}

int main(void)
{
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);
	std::cin >> k >> n;
	int i = 0;
	while (i < k)
	{
		std::cin >> arr[i];
		i++;
	}
	std::cout << solve(0, MAX) << "\n";
}