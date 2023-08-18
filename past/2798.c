#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	int	len;
	int	n;
	int	i;
	int	j;
	int	k;
	int	sum;
	int	temp;
	int	*card;

	scanf("%d %d", &len, &n);
	card = (int *)malloc(sizeof(int) * len);
	i = 0;
	while (i < len)
	{
		scanf("%d", &card[i]);
		i++;
	}
	i = 0;
	sum = 0;
	while (i < len)
	{
		j = i + 1;
		while (j < len)
		{
			k = j + 1;
			while (k < len)
			{
				temp = card[i] + card[j] + card[k];
				if (sum < temp && temp <= n)
					sum = temp;
				k++;
			}
			j++;
		}
		i++;
	}
	printf("%d", sum);
}
