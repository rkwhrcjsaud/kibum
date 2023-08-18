#include <iostream>

int n, k;

int solve(int left, int right)
{
	if (left > right)
		return left;
	int mid = (left + right) / 2;
	int i = 1;
	int sum = 0;
	while (i <= n)
	{
		sum += mid / i > n ? n : mid / i;
		i++;
	}
	if (sum >= k)
		return solve(left, mid - 1);
	return solve(mid + 1, right);
}

int main(void)
{
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);
	std::cin >> n >> k;
	std::cout << solve(1, k) << "\n";
}
