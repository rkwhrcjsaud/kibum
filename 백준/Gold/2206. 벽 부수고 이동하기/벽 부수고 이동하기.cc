#include <iostream>
#include <queue>
#include <vector>

int n, m;
int arr[1004][1004];
bool	visited[1004][1004][2];
std::queue < std::vector <int> > q;

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
	q.push(make_vector(2, 2, 1, 1));
	visited[2][2][1] = true;
	while (!q.empty())
	{
		int y = q.front()[0];
		int x = q.front()[1];
		int cnt = q.front()[2];
		int wall = q.front()[3];
		if (y == n + 1 && x == m + 1)
		{
			std::cout << cnt << "\n";
			return ;
		}
		q.pop();
		if (visited[y + 1][x][wall] == false && arr[y + 1][x] == 1)
		{
			visited[y + 1][x][wall] = true;
			q.push(make_vector(y + 1, x, cnt + 1, wall));
		}
		if (visited[y + 1][x][wall] == false && arr[y + 1][x] == 0 && wall == 1)
		{
			visited[y + 1][x][0] = true;
			q.push(make_vector(y + 1, x, cnt + 1, 0));
		}
		if (visited[y - 1][x][wall] == false && arr[y - 1][x] == 1)
		{
			visited[y - 1][x][wall] = true;
			q.push(make_vector(y - 1, x, cnt + 1, wall));
		}
		if (visited[y - 1][x][wall] == false && arr[y - 1][x] == 0 && wall == 1)
		{
			visited[y - 1][x][0] = true;
			q.push(make_vector(y - 1, x, cnt + 1, 0));
		}
		if (visited[y][x + 1][wall] == false && arr[y][x + 1] == 1)
		{
			visited[y][x + 1][wall] = true;
			q.push(make_vector(y, x + 1, cnt + 1, wall));
		}
		if (visited[y][x + 1][wall] == false && arr[y][x + 1] == 0 && wall == 1)
		{
			visited[y][x + 1][0] = true;
			q.push(make_vector(y, x + 1, cnt + 1, 0));
		}
		if (visited[y][x - 1][wall] == false && arr[y][x - 1] == 1)
		{
			visited[y][x - 1][wall] = true;
			q.push(make_vector(y, x - 1, cnt + 1, wall));
		}
		if (visited[y][x - 1][wall] == false && arr[y][x - 1] == 0 && wall == 1)
		{
			visited[y][x - 1][0] = true;
			q.push(make_vector(y, x - 1, cnt + 1, 0));
		}
	}
	std::cout << "-1\n";
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cin >> n >> m;
	int i = 2;
	while (i <= n + 1)
	{
		std::string str;
		std::cin >> str;
		int j = 2;
		while (j <= m + 1)
		{
			arr[i][j] = !(str[j - 2] - '0');
			j++;
		}
		i++;
	}
	bfs();
}