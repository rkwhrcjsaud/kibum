#include <iostream>

void	print_arr(int *arr, int m)
{
	int i = 0;
	while (i < m)
	{
		std::cout << arr[i++];
		if (i != m)
			std::cout << " ";
	}
	std::cout << "\n";
}

void	dfs(int n, int m, int depth, int *arr)
{
	if (depth == m)
	{
		print_arr(arr, m);
		return ;
	}
	int i = 1;
	while (i <= n)
	{
		arr[depth] = i;
		dfs(n, m, depth + 1, arr);
		i++;
	}
}

int main(void)
{
	int n, m;
	std::cin >> n;
	std::cin >> m;
	int	arr[m];
	int i = 0;
	while (i < m)
	{
		arr[i] = 0;
		i++;
	}
	dfs(n, m, 0, arr);
}