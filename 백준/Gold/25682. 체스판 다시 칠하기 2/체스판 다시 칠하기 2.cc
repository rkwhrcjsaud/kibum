#include <iostream>

#define MIN(a, b) (a < b ? a : b)

int n, m, k;
int	startB[2002][2002];
int	startW[2002][2002];
int min;

int main(void)
{
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);
	std::cin >> n >> m >> k;
	min = k * k;
	int i = 1;
	while (i <= n)
	{
		int j = 1;
		while (j <= m)
		{
			char	c;
			std::cin >> c;
			startB[i][j] = startB[i][j - 1] + startB[i - 1][j] - startB[i - 1][j - 1];
			startW[i][j] = startW[i][j - 1] + startW[i - 1][j] - startW[i - 1][j - 1];
			if ((i + j) % 2 == 0 && c == 'B')
				startW[i][j]++;
			if ((i + j) % 2 == 0 && c == 'W')
				startB[i][j]++;
			if ((i + j) % 2 == 1 && c == 'B')
				startB[i][j]++;
			if ((i + j) % 2 == 1 && c == 'W')
				startW[i][j]++;
			j++;
		}
		i++;
	}
	i = 0;
	while (i <= n - k)
	{
		int j = 0;
		while (j <= m - k)
		{
			int x2 = i + k;
			int y2 = j + k;
			int cntB = MIN(startW[x2][y2] - startW[x2][j] - startW[i][y2] + startW[i][j],
						startB[x2][y2] - startB[x2][j] - startB[i][y2] + startB[i][j]);
			min = MIN(min, cntB);
			j++;
		}
		i++;
	}
	std::cout << min << "\n";
}
