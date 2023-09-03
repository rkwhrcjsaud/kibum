#include <iostream>
#include <queue>
#include <vector>

int n, m;
int arr[1003][1003];
bool	visited[1003][1003];
std::queue < std::vector <int> > queue;

std::vector <int> make_vector(int a, int b, int c)
{
	std::vector <int> temp;
	temp.push_back(a);
	temp.push_back(b);
	temp.push_back(c);
	return (temp);
}

void	bfs(void)
{
	if (queue.empty())
	{
		std::cout << "-1\n";
		return ;
	}
	int max = 0;
	while (!queue.empty())
	{
		int y = queue.front()[0];
		int x = queue.front()[1];
		int cnt = queue.front()[2];
		if (max < cnt)
			max = cnt;
		queue.pop();
		if (visited[y + 1][x] == false && arr[y + 1][x] != -1)
		{
			visited[y + 1][x] = true;
			queue.push(make_vector(y + 1, x, cnt + 1));
		}
		if (visited[y - 1][x] == false && arr[y - 1][x] != -1)
		{
			visited[y - 1][x] = true;
			queue.push(make_vector(y - 1, x, cnt + 1));
		}
		if (visited[y][x + 1] == false && arr[y][x + 1] != -1)
		{
			visited[y][x + 1] = true;
			queue.push(make_vector(y, x + 1, cnt + 1));
		}
		if (visited[y][x - 1] == false && arr[y][x - 1] != -1)
		{
			visited[y][x - 1] = true;
			queue.push(make_vector(y, x - 1, cnt + 1));
		}
	}
	int i = 1;
	while (i <= n)
	{
		int j = 1;
		while (j <= m)
		{
			if (arr[i][j] != -1 && visited[i][j] == false)
			{
				std::cout << "-1\n";
				return ;
			}
			j++;
		}
		i++;
	}
	std::cout << max << "\n";
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cin >> m >> n;
	int i = 0;
	while (i <= 1002)
	{
		int j = 0;
		while (j <= 1002)
		{
			arr[i][j] = -1;
			j++;
		}
		i++;
	}
	i = 1;
	while (i <= n)
	{
		int j = 1;
		while (j <= m)
		{
			std::cin >> arr[i][j];
			if (arr[i][j] == 1)
			{
				queue.push(make_vector(i, j, 0));
				visited[i][j] = true;
			}
			j++;
		}
		i++;
	}
	bfs();
}