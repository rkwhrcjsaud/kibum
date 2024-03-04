#include <iostream>

int N, S;
int arr[55];

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cin >> N;
	for (int i = 0; i < N; i++)
		std::cin >> arr[i];
	std::cin >> S;
	int start = 0;
	while (S && start < N - 1)
	{
		int max = 0;
		int maxidx = 0;
		for (int i = start; i < N && i <= start + S; i++)
		{
			if (max < arr[i])
			{
				max = arr[i];
				maxidx = i;
			}
		}
		if (maxidx - start <= S)
		{
			S -= maxidx - start;
			for (int i = maxidx; i > start; i--)
				std::swap(arr[i], arr[i - 1]);
		}
		start++;
	}
	for (int i = 0; i < N; i++)
		std::cout << arr[i] << ' ';
	std::cout << '\n';
}