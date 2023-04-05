#include <stdio.h>

int	main(void)
{
	int	n;

	scanf("%d", &n);
	int	i = 0;
	int	j;
	int	temp;
	int	total = n / 3 + 1;
	while (i <= n / 3 + 1)
	{
		j = 0;
		while (j <= n / 3 + 1)
		{
			temp = n - (i * 3 + j * 5);
			if (temp == 0 && total > i + j)
				total = i + j;
			j++;
			if (temp < 0)
				break ;
		}
		i++;
	}
	if (total == n / 3 + 1)
		printf("%d", -1);
	else
		printf("%d", total);
}
