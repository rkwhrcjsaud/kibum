#include <iostream>

#define MAX 2147483647

typedef long long ll;

int	n, m;
int	arr[1000002];

int solve(ll left, ll right)
{
	if (left > right)
		return right;
	int i = 0;
	ll cnt = 0;
	ll mid = (left + right) / 2;
	while (i < n)
	{
		cnt += arr[i] > mid ? arr[i] - mid : 0;
		i++;
	}
	if (cnt >= m)
		return solve(mid + 1, right);
	else if (cnt < m)
		return solve(left, mid - 1);
	return (0);
}

int main(void)
{
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);
	std::cin >> n >> m;
	int i = 0;
	while (i < n)
		std::cin >> arr[i++];
	std::cout << solve(0, MAX) << "\n";
}