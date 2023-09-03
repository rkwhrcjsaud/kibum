#include <iostream>
#include <vector>
#include <queue>

int n, m;
std::queue < std::vector <int> > q;
bool	arr[102][102];
bool	visited[102][102];

std::vector <int> make_vector(int a, int b, int c)
{
	std::vector <int> temp;
	temp.push_back(a);
	temp.push_back(b);
	temp.push_back(c);
	return temp;
}

void	bfs(int x, int y)
{
	visited[y][x] = true;
	q.push(make_vector(y, x, 1));
	while (!q.empty())
	{
		int x_temp, y_temp, cnt;
		y_temp = q.front()[0];
		x_temp = q.front()[1];
		cnt = q.front()[2];
		if (y_temp == n && x_temp == m)
		{
			std::cout << cnt << "\n";
			return ;
		}
		q.pop();
		if (visited[y_temp + 1][x_temp] == false && arr[y_temp + 1][x_temp] == true)
		{
			visited[y_temp + 1][x_temp] = true;
			q.push(make_vector(y_temp + 1, x_temp, cnt + 1));
		}
		if (visited[y_temp][x_temp + 1] == false && arr[y_temp][x_temp + 1] == true)
		{
			visited[y_temp][x_temp + 1] = true;
			q.push(make_vector(y_temp, x_temp + 1, cnt + 1));
		}
		if (visited[y_temp - 1][x_temp] == false && arr[y_temp - 1][x_temp] == true)
		{
			visited[y_temp - 1][x_temp] = true;
			q.push(make_vector(y_temp - 1, x_temp, cnt + 1));
		}
		if (visited[y_temp][x_temp - 1] == false && arr[y_temp][x_temp - 1] == true)
		{
			visited[y_temp][x_temp - 1] = true;
			q.push(make_vector(y_temp, x_temp - 1, cnt + 1));
		}
	}
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cin >> n >> m;
	int i = 0;
	while (i < n)
	{
		std::string	str;
		std::cin >> str;
		int j = 0;
		while (j < m)
		{
			arr[i + 1][j + 1] = str[j] - '0';
			j++;
		}
		i++;
	}
	bfs(1, 1);
}