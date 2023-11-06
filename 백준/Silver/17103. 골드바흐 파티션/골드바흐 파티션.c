#include <stdio.h>
#include <stdlib.h>

char *let(void)
{
	int	n, m;
	n = 2;
	m = 1000000;
	int	max;
	max = 1;
	while (max < m / max)
		max++;
	char	*arr;
	arr = (char *)malloc(sizeof(char) * 1000001);
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
	return (arr);
}

int letlet(char *t, int n)
{
	int max;
	max = n / 2;
	int	i = 2;
	int total = 0;
	while (i <= max)
	{
		if (t[i] == 0)
		{
			i++;
			continue ;
		}
		else
		{
			if (t[n - i] == 1)
				total++;
		}
		i++;
	}
	return (total);
}

int	main(void)
{
	int	n;
	scanf("%d", &n);
	int	arr[n];
	int i = 0;
	char	*t;
	while (i < n)
	{
		int	t;
		scanf("%d", &t);
		arr[i++] = t;
	}
	i = 0;
	t = let();
	while (i < n)
	{
		printf("%d\n", letlet(t, arr[i]));
		i++;
	}
}
