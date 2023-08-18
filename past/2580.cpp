#include <iostream>

int sector(int n)
{
	if (n < 3)
		return 0;
	else if (n < 6)
		return 3;
	return 6;
}

bool check(int i, int j, int n, int k, int **arr)
{
	int m = 0;
	while (m < n)
	{
		if (arr[m][j] == k)
			return false;
		if (arr[i][m++] == k)
			return false;
	}
	int x = sector(i);
	int x2 = x + 3;
	int y = sector(j);
	int y2 = y + 3;
	while (x < x2)
	{
		int y1 = y;
		while (y1 < y2)
		{
			if (arr[x][y1] == k)
				return false;
			y1++;
		}
		x++;
	}
	return true;
}

void	print(int **arr)
{
	int i = 0;
	while (i < 9)
	{
		int j = 0;
		while (j < 9)
			std::cout << arr[i][j++] << " ";
		std::cout << "\n";
		i++;
	}
}

void	dfs(int *a, int n, int **arr, int depth)
{
	if (*a != -1 && depth == *a)
	{
		*a = -1;
		print(arr);
		return ;
	}
	int i = depth >> 4;
	while (i < n)
	{
		int j = 0;
		while (j < n)
		{
			if (arr[i][j] == 0)
			{
				int k = 1;
				while (k <= n)
				{
					if (*a == -1)
						return ;
					if (check(i, j, n, k, arr))
					{
						arr[i][j] = k;
						dfs(a, n, arr, (i << 4) + j);
						arr[i][j] = 0;
					}
					k++;
				}
				return ;
			}
			j++;
		}
		i++;
	}
}

int main(void)
{
	int	**arr = new int*[9];
	int i = 0;
	while (i < 9)
		arr[i++] = new int[9];
	i = 0;
	int a = 0;
	while (i < 9)
	{
		int j = 0;
		while (j < 9)
		{
			std::cin >> arr[i][j];
			if (!arr[i][j])
				a = (i << 4) + j;
			j++;
		}
		i++;
	}
	dfs(&a, 9, arr, 0);
	i = 0;
	while (i < 9)
		delete[] arr[i++];
	delete[] arr;
}