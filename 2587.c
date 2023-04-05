#include <stdio.h>

int	main(void)
{
	int	nbr[5];
	int	i = 0;
	while (i < 5)
	{
		scanf("%d", &nbr[i]);
		i++;
	}
	i = 0;
	int	temp;
	while (i < 4)
	{
		int	j = 0;
		while (j < 4)
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
	printf("%d\n", (nbr[0] + nbr[1] + nbr[2] + nbr[3] + nbr[4]) / 5);
	printf("%d", nbr[2]);
}
