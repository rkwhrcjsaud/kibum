#include <iostream>

int n, cnt1, cnt2, cnt3;
int	arr[2189][2189];

void	merge(int x1, int y1, int x2, int y2)
{
	int mid = (x2 - x1 + 1) / 3;
	int i = y1;
	while (i <= y2)
	{
		int j = x1;
		while (j <= x2)
		{
			if (arr[y1][x1] != arr[i][j])
				break ;
			j++;
		}
		if (j <= x2)
			break ;
		i++;
	}
	if (i > y2)
	{
		cnt1 += arr[y1][x1] == -1;
		cnt2 += arr[y1][x1] == 0;
		cnt3 += arr[y1][x1] == 1;
		return ;
	}
	i = y1;
	while (i <= y2)
	{
		int j = x1;
		while (j <= x2)
		{
			merge(j, i, j + mid - 1, i + mid - 1);
			j += mid;
		}
		i += mid;
	}
}

int main(void)
{
	std::ios_base :: sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cin >> n;
	int i = 1;
	while (i <= n)
	{
		int j = 1;
		while (j <= n)
			std::cin >> arr[i][j++];
		i++;
	}
	merge(1, 1, n, n);
	std::cout << cnt1 << "\n" << cnt2 << "\n" << cnt3 << "\n";
}