#include <stdio.h>

int	main(void)
{
	int	a1;
	int	a2;
	int	c;
	int	n;

	scanf("%d %d", &a1, &a2);
	scanf("%d", &c);
	scanf("%d", &n);
	while (n <= 100)
	{
		if (a1 * n + a2 > c * n)
		{
			printf("%d", 0);
			return (0);
		}
		n++;
	}
	printf("%d", 1);
	return (0);
}
