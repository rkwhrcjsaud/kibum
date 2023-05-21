#include <stdio.h>
#include <stdlib.h>

int	compare(const void *n1, const void *n2)
{
	return (*(int *)n1 - *(int *)n2);
}

int	search_card(int n, int *have_card, int left, int right)
{
	int	mid;

	while (left <= right)
	{
		mid = (left + right) / 2;
		if (n == have_card[mid])
			return (1);
		if (n < have_card[mid])
			right = mid - 1;
		else if (n > have_card[mid])
			left = mid + 1;
	}
	return (0);
}

int	main(void)
{
	int	n, m;
	scanf("%d", &n);
	int	have_card[n];
	int	i = 0;
	while (i < n)
		scanf("%d", &have_card[i++]);
	scanf("%d", &m);
	i = 0;
	int	card[m];
	while (i < m)
		scanf("%d", &card[i++]);
	qsort(have_card, n, sizeof(int), compare);
	i = 0;
	while (i < m)
	{
		printf("%d ", search_card(card[i], have_card, 0, n - 1));
		i++;
	}
}