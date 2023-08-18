#include <stdio.h>

int	main(void)
{
	int		m, n, i, j, k, l;
	int		cnt;
	int		total;

	scanf("%d %d", &m, &n);
	char	board[m][n];
	k = 0;
	total = 64;
	while (k < m)
	{
		scanf("%s", board[k]);
		k++;
	}
	i = 0;
	while (i + 7 < m)
	{
		j = 0;
		while (j + 7 < n)
		{
			k = 0;
			cnt = 0;
			while (k < 7)
			{
				l = 0;
				while (l < 7)
				{
					if (board[i + k][j + l] == 'B')
						cnt++;
					if (board[i + k + 1][j + l] == 'W')
						cnt++;
					if (board[i + k][j + l + 1] == 'W')
						cnt++;
					if (board[i + k + 1][j + l + 1] == 'B')
						cnt++;
					l += 2;
				}
				k += 2;
			}
			if (cnt < total)
				total = cnt;
			k = 0;
			cnt = 0;
			while (k < 7)
			{
				l = 0;
				while (l < 7)
				{
					if (board[i + k][j + l] == 'W')
						cnt++;
					if (board[i + k + 1][j + l] == 'B')
						cnt++;
					if (board[i + k][j + l + 1] == 'B')
						cnt++;
					if (board[i + k + 1][j + l + 1] == 'W')
						cnt++;
					l += 2;
				}
				k += 2;
			}
			if (cnt < total)
				total = cnt;
			j++;
		}
		i++;
	}
	printf("%d", total);
}
