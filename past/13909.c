#include <stdio.h>

int	main(void)
{
	int	n;
	scanf("%d", &n);
	int	i = 1;
	int	total = 0;
	while (i <= n / i)
	{
		total++;
		i++;
	}
	printf("%d\n", total);
}
