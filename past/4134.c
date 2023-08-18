#include <stdio.h>

int	main(void)
{
	unsigned int	n;
	scanf("%u", &n);
	unsigned int	arr[n];
	unsigned int i = 0;
	while (i < n)
		scanf("%u", &arr[i++]);
	i = 0;
	while (i < n)
	{
		unsigned int j = 2;
		while (j <= arr[i] / j)
		{
			if (arr[i] % j == 0)
			{
				j = 1;
				arr[i]++;
			}
			j++;
		}
		i++;
	}
	i = 0;
	while (i < n)
	{
		if (arr[i] <= 2)
			printf("%d\n", 2);
		else
			printf("%u\n", arr[i]);
		i++;
	}
}