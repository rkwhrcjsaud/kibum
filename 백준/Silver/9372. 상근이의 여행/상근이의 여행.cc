#include <iostream>

int T, N, M;

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cin >> T;
	while (T--)
	{
		std::cin >> N >> M;
		int i = 0;
		while (i < M)
		{
			int a, b;
			std::cin >> a >> b;
			i++;
		}
		std::cout << N - 1 << "\n";
	}
}