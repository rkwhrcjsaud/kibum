#include <stdio.h>

int	main(void)
{
	int				n;
	int				i;
	int				j;
	long long int	lln;

	scanf("%d", &n);
	lln = 0;
	i = 0;
	while (i < n)
	{
		j = 0;
		while (j < n)
		{
			lln += n;
			j++;
		}
		i++;
	}
	printf("%lld\n%d", lln, 3);
}
