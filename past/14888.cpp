#include <iostream>

void	recu(int *max, int *min, int n, int op[4], int depth, int ans, int *arr)
{
	if (depth == n - 1)
	{
		if (ans > *max)
			*max = ans;
		if (ans < *min)
			*min = ans;
		return ;
	}
	int i = 0;
	while (i < 4)
	{
		if (op[i] > 0)
		{
			int newAns = 0;
			if (i == 0)
				newAns = ans + arr[depth + 1];
			else if (i == 1)
				newAns = ans - arr[depth + 1];
			else if (i == 2)
				newAns = ans * arr[depth + 1];
			else if (i == 3)
				newAns = ans / arr[depth + 1];
			op[i] -= 1;
			recu(max, min, n, op, depth + 1, newAns, arr);
			op[i] += 1;
		}
		i++;
	}
}

int main()
{
	int	n;
	std::cin >> n;
	int i = 0;
	int	arr[n];
	while (i < n)
		std::cin >> arr[i++];
	int	op[4];
	i = 0;
	while (i < 4)
		std::cin >> op[i++];
	int max = -1000000000;
	int min = 1000000000;
	recu(&max, &min, n, op, 0, arr[0], arr);
	std::cout << max << "\n" << min << "\n";
}