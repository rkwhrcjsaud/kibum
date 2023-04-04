#include <stdio.h>

int	main(void)
{
	long long int	n;
	long long int	i;
	long long int	lln;

	scanf("%lld", &n);
	i = 1;
	lln = 0;
	while (i <= n - 2)
	{
		lln += (n - 1 - i) * i;
		i++;
	}
	printf("%lld\n%d", lln, 3);
}
