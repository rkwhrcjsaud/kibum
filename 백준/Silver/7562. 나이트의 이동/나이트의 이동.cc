#include <iostream>
#include <queue>
#include <vector>

int T, x_last, y_last;
bool visited[302][302];
std::queue < std::vector < int > > queue;

std::vector <int> make_vector(int a, int b, int c)
{
	std::vector <int> temp;
	temp.push_back(a);
	temp.push_back(b);
	temp.push_back(c);
	return temp;
}

void	bfs(int x, int y, int len)
{
	visited[y][x] = true;
	queue.push(make_vector(y, x, 0));
	while (!queue.empty())
	{
		int y_temp = queue.front()[0];
		int x_temp = queue.front()[1];
		int cnt = queue.front()[2];
		if (y_temp == y_last + 1 && x_temp == x_last + 1)
		{
			std::cout << cnt << "\n";
			return ;
		}
		queue.pop();
		if (y_temp + 2 <= len && x_temp + 1 <= len && visited[y_temp + 2][x_temp + 1] == false)
		{
			visited[y_temp + 2][x_temp + 1] = true;
			queue.push(make_vector(y_temp + 2, x_temp + 1, cnt + 1));
		}
		if (y_temp + 2 <= len && x_temp - 1 > 0 && visited[y_temp + 2][x_temp - 1] == false)
		{
			visited[y_temp + 2][x_temp - 1] = true;
			queue.push(make_vector(y_temp + 2, x_temp - 1, cnt + 1));
		}
		if (y_temp - 2 > 0 && x_temp + 1 <= len && visited[y_temp - 2][x_temp + 1] == false)
		{
			visited[y_temp - 2][x_temp + 1] = true;
			queue.push(make_vector(y_temp - 2, x_temp + 1, cnt + 1));
		}
		if (y_temp - 2 > 0 && x_temp - 1 > 0 && visited[y_temp - 2][x_temp - 1] == false)
		{
			visited[y_temp - 2][x_temp - 1] = true;
			queue.push(make_vector(y_temp - 2, x_temp - 1, cnt + 1));
		}
		if (y_temp + 1 <= len && x_temp + 2 <= len && visited[y_temp + 1][x_temp + 2] == false)
		{
			visited[y_temp + 1][x_temp + 2] = true;
			queue.push(make_vector(y_temp + 1, x_temp + 2, cnt + 1));
		}
		if (y_temp + 1 <= len && x_temp - 2 > 0 && visited[y_temp + 1][x_temp - 2] == false)
		{
			visited[y_temp + 1][x_temp - 2] = true;
			queue.push(make_vector(y_temp + 1, x_temp - 2, cnt + 1));
		}
		if (y_temp - 1 > 0 && x_temp + 2 <= len && visited[y_temp - 1][x_temp + 2] == false)
		{
			visited[y_temp - 1][x_temp + 2] = true;
			queue.push(make_vector(y_temp - 1, x_temp + 2, cnt + 1));
		}
		if (y_temp - 1 > 0 && x_temp - 2 > 0 && visited[y_temp - 1][x_temp - 2] == false)
		{
			visited[y_temp - 1][x_temp - 2] = true;
			queue.push(make_vector(y_temp - 1, x_temp - 2, cnt + 1));
		}
	}
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cin >> T;
	while (T--)
	{
		int len;
		std::cin >> len;
		int x1, y1, x2, y2;
		std::cin >> x1 >> y1 >> x_last >> y_last;
		bfs(x1 + 1, y1 + 1, len);
		int i = 1;
		while (i <= len)
		{
			int j = 1;
			while (j <= len)
				visited[i][j++] = false;
			i++;
		}
		while (!queue.empty())
			queue.pop();
	}
}