#include <stdio.h>

int	main(void)
{
	int	n, k;
	scanf("%d %d", &n, &k);
	int	a = 1;
	if (n > k * 2)
	{
		int	i;
		i = n - k + 1;
		while (i <= n)
			a *= i++;
		while (k > 0)
			a /= k--;
	}
	else
	{
		int i;
		i = k + 1;
		while (i <= n)
			a *= i++;
		while (n - k > 0)
		{
			a /= (n - k);
			k++;
		}
	}
	printf("%d\n", a);
}