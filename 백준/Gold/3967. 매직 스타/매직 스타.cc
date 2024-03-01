#include <iostream>

char arr[5][10];
bool visited[12];
int maxDEPTH;

void solution(int y, int x, int depth)
{
	if (depth == maxDEPTH)
	{
		if ((arr[0][4] - 'A') + (arr[1][3] - 'A') + (arr[2][2] - 'A') + (arr[3][1] - 'A') == 22 &&
			(arr[0][4] - 'A') + (arr[1][5] - 'A') + (arr[2][6] - 'A') + (arr[3][7] - 'A') == 22 &&
			(arr[1][1] - 'A') + (arr[2][2] - 'A') + (arr[3][3] - 'A') + (arr[4][4] - 'A') == 22 &&
			(arr[1][1] - 'A') + (arr[1][3] - 'A') + (arr[1][5] - 'A') + (arr[1][7] - 'A') == 22 &&
			(arr[1][7] - 'A') + (arr[2][6] - 'A') + (arr[3][5] - 'A') + (arr[4][4] - 'A') == 22 &&
			(arr[3][1] - 'A') + (arr[3][3] - 'A') + (arr[3][5] - 'A') + (arr[3][7] - 'A') == 22)
		{
			for (int i = 0; i < 5; i++)
			{
				for (int j = 0; j < 9; j++)
					std::cout << arr[i][j];
				std::cout << '\n';
			}
			exit(0);
		}
		return ;
	}
	while (arr[y][x] != 'x')
	{
		x++;
		if (x == 9)
		{
			x = 0;
			y++;
		}
		if (y == 5)
			break ;
	}
	for (int i = 0; i < 12; i++)
	{
		if (!visited[i])
		{
			arr[y][x] = 'A' + i;
			visited[i] = true;
			solution(y, x, depth + 1);
			visited[i] = false;
			arr[y][x] = 'x';
		}
	}
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			std::cin >> arr[i][j];
			if (arr[i][j] != '.' && arr[i][j] != 'x')
				visited[arr[i][j] - 'A'] = true;
			if (arr[i][j] == 'x')
				maxDEPTH++;
		}
	}
	solution(0, 0, 0);
}
