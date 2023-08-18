#include <stdio.h>

int	main(void)
{
	int	n;

	scanf("%d", &n);
	int	nbr[n];
	int	i = 0;
	while (i < n)
	{
		scanf("%d", &nbr[i]);
		i++;
	}
	merge_sort(nbr, 0, n - 1);
	i = 0;
	while (i < n)
	{
		printf("%d\n", nbr[i]);
		i++;
	}
}
