#include <iostream>

int	n;
bool	arr[65][65];

void	merge(int x1, int y1, int x2, int y2)
{
	int mid = (x2 - x1 + 1) >> 1;
	int i = x1;
	while (i <= x2)
	{
		int j = y1;
		while (j <= y2)
		{
			if (arr[i][j] != arr[x1][y1])
				break ;
			j++;
		}
		if (j <= y2)
			break ;
		i++;
	}
	if (i > x2)
	{
		std::cout << arr[x1][y1];
		return ;
	}
	std::cout << "(";
	merge(x1, y1, x1 + mid - 1, y1 + mid - 1);
	merge(x1, y1 + mid, x1 + mid - 1, y2);
	merge(x2 - mid + 1, y1, x2, y1 + mid - 1);
	merge(x1 + mid, y2 - mid + 1, x2, y2);
	std::cout << ")";
}

int main(void)
{
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);
	std::cin >> n;
	int i = 0;
	while (i < n)
	{
		std::string temp;
		std::cin >> temp;
		int j = 0;
		while (j < n)
		{
			arr[i][j] = temp[j] - '0';
			j++;
		}
		i++;
	}
	merge(0, 0, n - 1, n - 1);
	std::cout << "\n";
}