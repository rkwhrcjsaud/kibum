#include <stdio.h>
#include <stdlib.h>

void	merge(int *nbr, int left, int mid, int right)
{
	int	i, j, k;
	int	*sort;

	i = left;
	j = mid + 1;
	k = 0;
	sort = (int *)malloc(sizeof(int) * (right - left));
	while (i <= mid && j <= right)
	{
		if (nbr[i] < nbr[j])
			sort[k++] = nbr[i++];
		else
			sort[k++] = nbr[j++];
	}
	if (i > mid)
	{
		while (j <= right)
			sort[k++] = nbr[j++];
	}
	else
	{
		while (i <= mid)
			sort[k++] = nbr[i++];
	}
	k = 0;
	while (left + k <= right)
	{
		nbr[left + k] = sort[k];
		k++;
	}
	free(sort);
}

void	merge_sort(int	*nbr, int left, int right)
{
	int	mid;

	if (right > left)
	{
		mid = (right + left) / 2;
		merge_sort(nbr, left, mid);
		merge_sort(nbr, mid + 1, right);
		merge(nbr, left, mid, right);
	}
}

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
	merge_sort(nbr, 0, n - 1);
	i = 0;
	while (i < n)
	{
		printf("%d\n", nbr[i]);
		i++;
	}
}
