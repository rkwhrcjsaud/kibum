#include <iostream>
#include <vector>
#include <algorithm>

int n;
bool	arr[27][27];
bool	visited[27][27];
std::vector <int> cnt;

int dfs(int y, int x, int c)
{
	visited[y][x] = true;
	if (arr[y + 1][x] == true && visited[y + 1][x] == false)
		c = dfs(y + 1, x, c + 1);
	if (arr[y][x + 1] == true && visited[y][x + 1] == false)
		c = dfs(y, x + 1, c + 1);
	if (arr[y - 1][x] == true && visited[y - 1][x] == false)
		c = dfs(y - 1, x, c + 1);
	if (arr[y][x - 1] == true && visited[y][x - 1] == false)
		c = dfs(y, x - 1, c + 1);
	return (c);
}

int compare(int a, int b)
{
	return (a < b);
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cin >> n;
	int i = 1;
	while (i <= n)
	{
		int j = 1;
		std::string	str;
		std::cin >> str;
		while (j <= n)
		{
			arr[i][j] = str[j - 1] - '0';
			j++;
		}
		i++;
	}
	i = 1;
	while (i <= n)
	{
		int j = 1;
		while (j <= n)
		{
			if (visited[i][j] == false && arr[i][j] == true)
				cnt.push_back(dfs(i, j, 1));
			j++;
		}
		i++;
	}
	std::sort(cnt.begin(), cnt.end(), compare);
	i = 0;
	int size = cnt.size();
	std::cout << size << "\n";
	while (i < size)
		std::cout << cnt[i++] << "\n";
}