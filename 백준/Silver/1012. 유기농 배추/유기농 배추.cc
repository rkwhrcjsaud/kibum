#include <iostream>

int T;
bool	arr[52][52];
bool	visited[52][52];

void	dfs(int y, int x)
{
	visited[y][x] = true;
	if (visited[y + 1][x] == false && arr[y + 1][x] == true)
		dfs(y + 1, x);
	if (visited[y][x + 1] == false && arr[y][x + 1] == true)
		dfs(y, x + 1);
	if (visited[y - 1][x] == false && arr[y - 1][x] == true)
		dfs(y - 1, x);
	if (visited[y][x - 1] == false && arr[y][x - 1] == true)
		dfs(y, x - 1);
}

int	solve(int x, int y)
{
	int c = 0;
	int i = 1;
	while (i <= y)
	{
		int j = 1;
		while (j <= x)
		{
			if (arr[i][j] == true && visited[i][j] == false)
			{
				c++;
				dfs(i, j);	
			}
			j++;
		}
		i++;
	}
	return (c);
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cin >> T;
	while (T--)
	{
		int x, y, k;
		std::cin >> x >> y >> k;
		int i = 1;
		while (i <= k)
		{
			int x_temp, y_temp;
			std::cin >> x_temp >> y_temp;
			arr[y_temp + 1][x_temp + 1] = true;
			i++;
		}
		std::cout << solve(x, y) << "\n";
		i = 1;
		while (i <= y)
		{
			int j = 1;
			while (j <= x)
			{
				arr[i][j] = false;
				visited[i][j++] = false;
			}
			i++;
		}
	}
}