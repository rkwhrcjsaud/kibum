#include <iostream>

int	cntB, cntW, n;
bool	arr[(1 << 8) + 1][(1 << 8) + 1];

void	merge(int x1, int y1, int x2, int y2)
{
	if (x1 == x2 && y1 == y2)
	{
		cntB += (arr[x1][y1] == true);
		cntW += (arr[x1][y1] == false);
		return ;
	}
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
		cntB += (arr[x1][y1] == true);
		cntW += (arr[x1][y1] == false);
		return ;
	}
	merge(x1, y1, x1 + mid - 1, y1 + mid - 1);
	merge(x2 - mid + 1, y1, x2, y1 + mid - 1);
	merge(x1, y1 + mid, x1 + mid - 1, y2);
	merge(x1 + mid, y2 - mid + 1, x2, y2);
}

int main(void)
{
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);
	std::cin >> n;
	int i = 0;
	while (i < n)
	{
		int j = 0;
		while (j < n)
			std::cin >> arr[i][j++];
		i++;
	}
	merge(0, 0, n - 1, n - 1);
	std::cout << cntW << "\n" << cntB << "\n";
}