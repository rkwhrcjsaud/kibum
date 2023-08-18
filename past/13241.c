
#include <stdio.h>

int	main(void)
{
	unsigned long long int	a, b;
	scanf("%llu %llu", &a, &b);
	int i = 1;
	int t = 0;
	while (i <= a || i <= b)
	{
		if (a % i == 0 && b % i == 0)
			t = i;
		i++;
	}
	printf("%llu\n", a * b / t);
}