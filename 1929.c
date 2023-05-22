#include <stdio.h>

int	main(void)
{
	int	n, m;
	scanf("%d %d", &n, &m);
	int	max;
	max = 1;
	while (max < m / max)
		max++;
	char	arr[m + 1];
	if (n < 2)
		n = 2;
	int	i = 0;
	while (i < m + 1)
		arr[i++] = 1;
	i = 2;
	while (i <= max)
	{
		int j = 2;
		while (i * j <= m)
		{
			arr[i * j] = 0;
			j++;
		}
		i++;
		while (arr[i] == 0)
			i++;
	}
	while (n <= m)
	{
		if (arr[n] == 1)
			printf("%d\n", n);
		n++;
	}
}