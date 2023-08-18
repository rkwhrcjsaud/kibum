#include <iostream>

bool check(int i, int j, int n, bool **arr)
{
	int k = 0;
	while (k <= i)
	{
		if (arr[k][j])
			return false;
		else if (j - k >= 0 && arr[i - k][j - k])
			return false;
		else if (j + k < n && arr[i - k][j + k])
			return false;
		k++;
	}
	return true;
}

void	dfs(int *a, int n, bool **arr, int depth)
{
	if (depth == n)
	{
		(*a)++;
		return ;
	}
	int i = depth;
	int j = 0;
	while (j < n)
	{
		if (check(i, j, n, arr))
		{
			arr[i][j] = true;
			dfs(a, n, arr, depth + 1);
			arr[i][j] = false;
		}
		j++;
	}
}

int main(void)
{
	int n;
	std::cin >> n;
	bool	**arr = new bool*[n];
	int i = 0;
	while (i < n)
		arr[i++] = new bool[n];
	i = 0;
	while (i < n)
	{
		int j = 0;
		while (j < n)
			arr[i][j++] = false;
		i++;
	}
	int a = 0;
	dfs(&a, n, arr, 0);
	std::cout << a << "\n";
	i = 0;
	while (i < n)
		delete[] arr[i++];
	delete[] arr;
}