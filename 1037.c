#include <stdio.h>

int	main(void)
{
	int	n;
	scanf("%d", &n);
	int	i = 0;
	int	arr[n];
	while (i < n)
		scanf("%d", &arr[i++]);
	int	max = 0;
	int	min = 1000000;
	i = 0;
	while (i < n)
	{
		if (max < arr[i])
			max = arr[i];
		if (min > arr[i])
			min = arr[i];
		i++;
	}
	printf("%d\n", max * min);
}