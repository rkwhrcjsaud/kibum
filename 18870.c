#include <stdio.h>
#include <stdlib.h>

void	merge(int *nbr, int left, int mid, int right)
{
	int	i, j, k;
	int	sort[right - left + 1];

	i = left;
	j = mid + 1;
	k = 0;
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

int	search_index(int n, int *sort, int left, int right)
{
	int	mid;

	while (right > left)
	{
		mid = (right + left) / 2;
		if (n == sort[mid])
			return (mid);
		if (n < sort[mid])
			right = mid - 1;
		else if (n > sort[mid])
			left = mid + 1;
	}
	return (left);
}

int	main(void)
{
	int	n;
	scanf("%d", &n);
	int	nbr[n];
	int	sort[n];
	int	ssort[n];
	int	i = 0;

	while (i < n)
	{
		scanf("%d", &nbr[i]);
		sort[i] = nbr[i];
		i++;
	}
	merge_sort(sort, 0, n - 1);
	int	j = 1;
	i = 1;
	ssort[0] = sort[0];
	while (i < n)
	{
		if (sort[i - 1] != sort[i])
			ssort[j++] = sort[i];
		i++;
	}
	i = 0;
	while (i < n)
	{
		printf("%d ", search_index(nbr[i], ssort, 0, j - 1));
		i++;
	}
	return (0);
}
