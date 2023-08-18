#include <stdio.h>

int	main(void)
{
	int				n;
	long long int	lln;

	scanf("%d", &n);
	lln = 0;
	while (n - 1 > 0)
	{
		lln += n - 1;
		n--;
	}
	printf("%lld\n%d", lln, 2);
}