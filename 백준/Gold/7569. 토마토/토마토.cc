#include <iostream>
#include <queue>
#include <vector>

int n, m, h;
int arr[102][102][102];
bool	visited[102][102][102];
std::queue < std::vector <int> > queue;

std::vector <int> make_vector(int a, int b, int c, int d)
{
	std::vector <int> temp;
	temp.push_back(a);
	temp.push_back(b);
	temp.push_back(c);
	temp.push_back(d);
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
		int z = queue.front()[0];
		int y = queue.front()[1];
		int x = queue.front()[2];
		int cnt = queue.front()[3];
		if (max < cnt)
			max = cnt;
		queue.pop();
		if (visited[z][y + 1][x] == false && arr[z][y + 1][x] != -1)
		{
			visited[z][y + 1][x] = true;
			queue.push(make_vector(z, y + 1, x, cnt + 1));
		}
		if (visited[z][y - 1][x] == false && arr[z][y - 1][x] != -1)
		{
			visited[z][y - 1][x] = true;
			queue.push(make_vector(z, y - 1, x, cnt + 1));
		}
		if (visited[z][y][x + 1] == false && arr[z][y][x + 1] != -1)
		{
			visited[z][y][x + 1] = true;
			queue.push(make_vector(z, y, x + 1, cnt + 1));
		}
		if (visited[z][y][x - 1] == false && arr[z][y][x - 1] != -1)
		{
			visited[z][y][x - 1] = true;
			queue.push(make_vector(z, y, x - 1, cnt + 1));
		}
		if (visited[z + 1][y][x] == false && arr[z + 1][y][x] != -1)
		{
			visited[z + 1][y][x] = true;
			queue.push(make_vector(z + 1, y, x, cnt + 1));
		}
		if (visited[z - 1][y][x] == false && arr[z - 1][y][x] != -1)
		{
			visited[z - 1][y][x] = true;
			queue.push(make_vector(z - 1, y, x, cnt + 1));
		}
	}
	int i = 1;
	while (i <= h)
	{
		int j = 1;
		while (j <= n)
		{
			int k = 1;
			while (k <= m)
			{
				if (arr[i][j][k] != -1 && visited[i][j][k] == false)
				{
					std::cout << "-1\n";
					return ;
				}
				k++;
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
	std::cin >> m >> n >> h;
	int i = 0;
	while (i < 102)
	{
		int j = 0;
		while (j < 102)
		{
			int k = 0;
			while (k < 102)
			{
				arr[i][j][k] = -1;
				k++;
			}
			j++;
		}
		i++;
	}
	i = 1;
	while (i <= h)
	{
		int j = 1;
		while (j <= n)
		{
			int k = 1;
			while (k <= m)
			{
				std::cin >> arr[i][j][k];
				if (arr[i][j][k] == 1)
				{
					visited[i][j][k] = true;
					queue.push(make_vector(i, j, k, 0));
				}
				k++;
			}
			j++;
		}
		i++;
	}
	bfs();
}