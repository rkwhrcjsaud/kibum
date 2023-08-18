#include <stdio.h>
#include <stdlib.h>

int	let_gcd(int a, int b)
{
	int	big, small;

	big = (a > b) * a + (a <= b) * b;
	small = (a < b) * a + (a >= b) * b;
	while (1)
	{
		if (big % small != 0)
		{
			int temp;
			temp = big % small;
			big = small;
			small = temp;
		}
		else
			break ;
	}
	return (small);
}

int	compare(const void *a, const void *b)
{
	return (*(int *)b - *(int *)a);
}

int	main(void)
{
	int	n;
	scanf("%d", &n);
	int	arr[n];
	int	i = 0;
	while (i < n)
	{
		scanf("%d", &arr[i]);
		i++;
	}
	qsort(arr, n, sizeof(int), compare);
	i = 2;
	int	gcd;
	gcd = let_gcd(arr[1] - arr[0], arr[2] - arr[1]);
	while (i < n - 1)
	{
		gcd = let_gcd(gcd, arr[i + 1] - arr[i]);
		i++;
	}
	i = 0;
	int	total = 0;
	while (i < n - 1)
	{
		total += (arr[i + 1] - arr[i]) / gcd - 1;
		i++;
	}
	printf("%d\n", total);
}