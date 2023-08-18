#include <stdio.h>

int	main(void)
{
	int	n;

	scanf("%d", &n);
	int	nbr[n];
	int	i = 0;
	while (i < n)
	{
		scanf("%d", &nbr[i]);
		i++;
	}
	i = 0;
	int	temp;
	while (i < n - 1)
	{
		int	j = 0;
		while (j < n - 1)
		{
			if (nbr[j] > nbr[j + 1])
			{
				temp = nbr[j];
				nbr[j] = nbr[j + 1];
				nbr[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
	i = 0;
	while (i < n)
	{
		printf("%d\n", nbr[i]);
		i++;
	}
}