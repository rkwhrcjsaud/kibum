#include <iostream>

int N, K;
int d[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
int dp[1001][1001][4];

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cin >> N >> K;
	int posx, posy;
	char arr[N + 1][N + 1];
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			std::cin >> arr[i][j];
			if (arr[i][j] == 'L')
			{
				posx = j, posy = i;
				arr[i][j] = '.';
			}
		}
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (arr[i][j] == 'X')
				continue ;
			for (int k = 0; k < 4; k++)
			{
				if (i - d[k][0] >= 0 && j - d[k][1] >= 0 
					&& i - d[k][0] < N && j - d[k][1] < N && dp[i - d[k][0]][j - d[k][1]][k])
					dp[i][j][k] = dp[i - d[k][0]][j - d[k][1]][k] - d[k][0] - d[k][1];
				else
				{
					for (int di = i + d[k][0], dj = j + d[k][1]; di >= 0 && dj >= 0 && di < N && dj < N && arr[di][dj] != 'X'; di += d[k][0], dj += d[k][1])
						dp[i][j][k]++;
				}
			}
		}
	}
	int rotate = 0;
	for (int i = 0; i < K; i++)
	{
		char c;
		std::cin >> c;
		if (c == 'L')
		{
			rotate--;
			if (rotate == -1)
				rotate = 3;
		}
		else
		{
			rotate++;
			if (rotate == 4)
				rotate = 0;
		}
		posy += d[rotate][0] * (dp[posy][posx][rotate]);
		posx += d[rotate][1] * (dp[posy][posx][rotate]);
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			int printx, printy;
			switch (rotate)
			{
				case 0:
					printy = i, printx = j;
					break ;
				case 1:
					printy = N - 1 - j, printx = i;
					break ;
				case 2:
					printy = N - 1 - i, printx = N - 1 - j;
					break ;
				case 3:
					printy = j, printx = N - 1 - i;
					break ;
			}
			if (printx == posx && printy == posy)
				std::cout << 'L';
			else
				std::cout << arr[printy][printx];
		}
		std::cout << '\n';
	}
}
