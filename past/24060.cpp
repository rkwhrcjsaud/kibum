#include <iostream>

void	merge(int *nbr, int left, int mid, int right, int *cnt, int m)
{
	int	i, j, k;
	int	sort[right - left + 1];

	i = left;
	j = mid + 1;
	k = 0;
	if (*cnt == m)
		return ;
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
		(*cnt)++;
		nbr[left + k] = sort[k];
		if (*cnt == m)
		{
			std::cout << sort[k] << std::endl;
			return ;
		}
		k++;
	}
}

void	merge_sort(int	*nbr, int left, int right, int *cnt, int m)
{
	int	mid;

	if (*cnt == m)
		return ;
	if (right > left)
	{
		mid = (right + left) / 2;
		merge_sort(nbr, left, mid, cnt, m);
		merge_sort(nbr, mid + 1, right, cnt, m);
		merge(nbr, left, mid, right, cnt, m);
	}
}

int main(void)
{
	int n, m;
	std::cin >> n;
	std::cin >> m;
	int a[n];
	int i = 0;
	while (i < n)
		std::cin >> a[i++];
	int cnt = 0;
	merge_sort(a, 0, n - 1, &cnt, m);
	i = 0;
	if (cnt < m)
		std::cout << "-1" << std::endl;
}