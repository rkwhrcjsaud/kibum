#include <stdio.h>

int	issix(int n)
{
	while (n)
	{
		if (n % 10 == 6)
		{
			n /= 10;
			if (n % 10 == 6)
			{
				n /= 10;
				if (n % 10 == 6)
					return (1);
			}
		}
		n /= 10;
	}
	return (0);
}

int	main(void)
{
	int	n, i, j;

	scanf("%d", &n);
	i = 0;
	j = 665;
	while (i < n)
	{
		j++;
		if (issix(j))
			i++;
	}
	printf("%d", j);
}
