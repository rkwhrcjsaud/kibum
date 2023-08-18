#include <stdio.h>
#include <stdlib.h>

typedef struct s_acc
{
	char	name[101];
	int		age;
}	t_acc;

void	merge(t_acc *acc, int left, int mid, int right)
{
	int		i, j, k;
	t_acc	*sort;

	i = left;
	j = mid + 1;
	k = 0;
	sort = (t_acc *)malloc(sizeof(t_acc) * (right - left + 1));
	while (i <= mid && j <= right)
	{
		if (acc[i].age <= acc[j].age)
			sort[k++] = acc[i++];
		else
			sort[k++] = acc[j++];
	}
	if (i > mid)
	{
		while (j <= right)
			sort[k++] = acc[j++];
	}
	else
	{
		while (i <= mid)
			sort[k++] = acc[i++];
	}
	k = 0;
	while (left + k <= right)
	{
		acc[left + k] = sort[k];
		k++;
	}
	free(sort);
}

void	merge_sort(t_acc *acc, int left, int right)
{
	int	mid;

	if (right > left)
	{
		mid = (right + left) / 2;
		merge_sort(acc, left, mid);
		merge_sort(acc, mid + 1, right);
		merge(acc, left, mid, right);
	}
}

int	main(void)
{
	int	n;

	scanf("%d", &n);
	t_acc	acc[n + 1];
	int	i = 0;
	while (i < n)
	{
		scanf("%d %s", &(acc[i].age), acc[i].name);
		(acc[i].name)[100] = '\0';
		i++;
	}
	merge_sort(acc, 0, n - 1);
	i = 0;
	while (i < n)
	{
		printf("%d %s\n", acc[i].age, acc[i].name);
		i++;
	}
	return (0);
}
