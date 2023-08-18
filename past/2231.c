#include <stdio.h>

int	main(void)
{
	int	n;
	int	i;
	int	cpi;
	int	temp;

	scanf("%d", &n);
	i = 1;
	while (i <= n)
	{
		temp = 0;
		cpi = i;
		while (cpi)
		{
			temp += cpi % 10;
			cpi /= 10;
		}
		temp += i;
		if (temp == n)
		{
			printf("%d", i);
			return (0);
		}
		i++;
	}
	printf("%d", 0);
	return (0);
}