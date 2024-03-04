#include <iostream>

int N;
int arr[10010];

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cin >> N;
	for (int i = 0; i < N; i++)
		std::cin >> arr[i];
	long long sum = 0;
	for (int i = 0; i < N; i++)
	{
		if (arr[i + 1] > arr[i + 2])
		{
			int max = std::min(arr[i], arr[i + 1] - arr[i + 2]);
			sum += max * 5;
			arr[i] -= max;
			arr[i + 1] -= max;
			max = std::min(arr[i], arr[i + 2]);
			sum += max * 7;
			arr[i] -= max;
			arr[i + 1] -= max;
			arr[i + 2] -= max;
			sum += arr[i] * 3;
			arr[i] = 0;
		}
		else
		{
			int max = std::min(arr[i], arr[i + 1]);
			sum += max * 7;
			arr[i] -= max;
			arr[i + 1] -= max;
			arr[i + 2] -= max;
			max = arr[i];
			sum += max * 3;
			arr[i] -= max;
		}
	}
	std::cout << sum << '\n';
}