#include <stdio.h>

long long int	let(int n, int k)
{
	long long int	a = 1;
	if (n > k * 2)
	{
		long long int	i;
		i = n - k + 1;
		while (i <= n || k > 0)
		{
			if (i <= n)
				a *= i++;
			if (k > 0 && a % k == 0)
				a /= k--;
		}
	}
	else
	{
		long long int i;
		i = k + 1;
		while (i <= n || n - k > 0)
		{
			if (i <= n)
				a *= i++;
			if (n - k > 0 && a % (n - k) == 0)
			{
				a /= (n - k);
				k++;
			}
		}
	}
	return (a);
}

int	main(void)
{
	int	n;
	scanf("%d", &n);
	int	i = 0;
	int arr[2 * n];
	while (i < n)
	{
		scanf("%d %d", &arr[i * 2], &arr[i * 2 + 1]);
		i++;
	}
	i = 0;
	while (i < n)
	{
		printf("%lli\n", let(arr[i * 2 + 1], arr[i * 2]));
		i++;
	}
}