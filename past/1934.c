#include <stdio.h>

int	main(void)
{
	int	n;
	scanf("%d", &n);
	int	arr[n];
	int	j = 0;
	while (j < n)
	{
		int	a, b;
		scanf("%d %d", &a, &b);
		int i = 1;
		int t = 0;
		while (i <= a || i <= b)
		{
			if (a % i == 0 && b % i == 0)
				t = i;
			i++;
		}
		arr[j] = a * b / t;
		j++;
	}
	j = 0;
	while (j < n)
		printf("%d\n", arr[j++]);
}