#include <stdio.h>

int	main(void)
{
	int	n;
	scanf("%d", &n);
	int	i = 1;
	int	a = 2;
	while (i++ < n)
		a *= 2;
	printf("%d\n", a);
}