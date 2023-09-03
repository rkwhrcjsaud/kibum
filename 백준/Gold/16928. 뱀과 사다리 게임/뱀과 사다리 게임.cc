#include <iostream>
#include <queue>

int n, m;
bool	visited[102];
int	sadari[102];
int	snake[102];
std::queue <std::pair <int, int> > q;

void	bfs(void)
{
	q.push(std::make_pair(1, 0));
	visited[1] = true;
	while (!q.empty())
	{
		int temp = q.front().first;
		int cnt = q.front().second;
		if (temp == 100)
		{
			std::cout << cnt << "\n";
			return ;
		}
		q.pop();
		if (sadari[temp] != 0)
		{
			visited[sadari[temp]] = true;
			temp = sadari[temp];
		}
		if (snake[temp] != 0)
		{
			visited[snake[temp]] = true;
			temp = snake[temp];
		}
		int i = 1;
		while (i <= 6)
		{
			if (temp + i <= 100 && visited[temp + i] == false)
			{
				visited[temp + i] = true;
				q.push(std::make_pair(temp + i, cnt + 1));
			}
			i++;
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
		int temp1, temp2;
		std::cin >> temp1 >> temp2;
		sadari[temp1] = temp2;
		i++;
	}
	i = 0;
	while (i < m)
	{
		int temp1, temp2;
		std::cin >> temp1 >> temp2;
		snake[temp1] = temp2;
		i++;
	}
	bfs();
}