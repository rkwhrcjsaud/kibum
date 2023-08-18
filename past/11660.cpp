#include <iostream>

int n, m;
int	arr[1025][1025];

int main(void)
{
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);
	std::cin >> n >> m;
	int i = 1;
	while (i <= n)
	{
		int j = 1;
		while (j <= n)
		{
			int temp;
			std::cin >> temp;
			arr[i][j] = arr[i - 1][j] + arr[i][j - 1] - arr[i - 1][j - 1] + temp;
			j++;
		}
		i++;
	}
	i = 1;
	while (i <= m)
	{
		int x1, y1, x2, y2;
		std::cin >> x1 >> y1 >> x2 >> y2;
		std::cout << arr[x2][y2] - arr[x1 - 1][y2] - arr[x2][y1 - 1] + arr[x1 - 1][y1 - 1] << "\n";
		i++;
	}
}