#include <iostream>

int N;
int arr[100010];

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cin >> N;
	int prev;
	std::cin >> prev;
	int tie = 0;
	arr[tie]++;
	for (int i = 1; i < N; i++)
	{
		int tmp;
		std::cin >> tmp;
		if (tmp == prev)
		{
			tie++;
			arr[tie]++;
		}
		else
		{
			prev = tmp;
			arr[tie]++;
		}
	}
	int ans = 0;
	for (int i = 0; i <= tie; i++)
	{
		if (ans < arr[i] + arr[i + 1] + arr[i + 2])
			ans = arr[i] + arr[i + 1] + arr[i + 2];
	}
	std::cout << ans << '\n';
}
