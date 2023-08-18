#include <iostream>

void	makeHole(std::string *arr, int x1, int y1, int x2, int y2)
{
	if (x1 < x2 && y1 < y2)
	{
		int interval = (x2 - x1 + 1) / 3;
		makeHole(arr, x1, y1, x1 + interval - 1, y1 + interval - 1);
		makeHole(arr, x1 + interval, y1, x2 - interval, y1 + interval - 1);
		makeHole(arr, x2 - interval + 1, y1, x2, y1 + interval - 1);

		makeHole(arr, x1, y1 + interval, x1 + interval - 1, y2 - interval);
		makeHole(arr, x2 - interval + 1, y1 + interval, x2, y2 - interval);

		makeHole(arr, x1, y2 - interval + 1, x1 + interval - 1, y2);
		makeHole(arr, x1 + interval, y2 - interval + 1, x2 - interval, y2);
		makeHole(arr, x2 - interval + 1, y2 - interval + 1, x2, y2);

		while (y1 + interval <= y2 - interval)
		{
			int j = x1 + interval;
			while (j <= x2 - interval)
			{
				arr[y1 + interval][j] = ' ';
				j++;
			}
			y1++;
		}
	}
}

int main(void)
{
	int n;
	std::cin >> n;
	std::string arr[n];
	int i = 0;
	while (i < n)
	{
		int j = 0;
		while (j++ < n)
			arr[i] += "*";
		i++;
	}
	makeHole(arr, 0, 0, n - 1, n - 1);
	i = 0;
	while (i < n)
	{
		std::cout << arr[i];
		std::cout << std::endl;
		i++;
	}
}