#include <iostream>

int arr[21][21];
bool arr_n[21];
int min = 2147483647;
int n;

void	dfs(int depth, int cnt)
{
	if (depth == n >> 1)
	{
		int start = 0, link = 0, i = 0;
		while (i < n - 1)
		{
			int j = i + 1;
			while (j < n)
			{
				if (arr_n[i] && arr_n[j])
				{
					start += arr[i][j];
					start += arr[j][i];
				}
				if (!arr_n[i] && !arr_n[j])
				{
					link += arr[i][j];
					link += arr[j][i];
				}
				j++;
			}
			i++;
		}
		int temp = abs(start - link);
		if (min > temp)
			min = temp;
		return ;
	}
	int i = cnt;
	while (i < n)
	{
		if (depth == 0 && i > 0)
			return ;
		if (arr_n[i] == false)
		{
			arr_n[i] = true;
			dfs(depth + 1, cnt + 1);
			arr_n[i] = false;
		}
		i++;
		cnt++;
	}
}

int main(void)
{
	std::cin >> n;
	int i = 0;
	while (i < n)
	{
		int j = 0;
		while (j < n)
			std::cin >> arr[i][j++];
		i++;
	}
	dfs(0, 0);
	std::cout << min << std::endl;
}