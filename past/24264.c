#include <stdio.h>

int	main(void)
{
	int				n;
	int				cpn;
	long long int	lln;

	scanf("%d", &n);
	lln = 0;
	cpn = n;
	while (cpn > 0)
	{
		lln += n;
		cpn--;
	}
	printf("%lld\n%d", lln, 2);
}