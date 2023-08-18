#include <iostream>
#include <algorithm>

int n;
int arr[1002];

int main(void)
{
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);
	std::cin >> n;
	int i = 1;
	while (i <= n)
		std::cin >> arr[i++];
	std::sort(arr + 1, arr + n + 1);
	i = 1;
	int ans = 0;
	while (i <= n)
	{
		arr[i] += arr[i - 1];
		ans += arr[i];
		i++;
	}
	std::cout << ans << "\n";
}