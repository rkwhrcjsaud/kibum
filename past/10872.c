#include <stdio.h>

int	main(void)
{
	int	n;
	scanf("%d", &n);
	int	i = 1;
	int	a = 1;
	while (i <= n)
		a *= i++;
	printf("%d\n", a);
}