#include <iostream>
#include <queue>
#include <stack>

int n, k;
int	visited[100002][2];
std::queue < std::pair <int, int> > q;
std::stack < int > s;

void	bfs(int a)
{
	visited[a][0] = true;
	visited[a][1] = -1;
	q.push(std::make_pair(a, 0));
	while (!q.empty())
	{
		int temp = q.front().first;
		int cnt = q.front().second;
		if (temp == k)
		{
			std::cout << cnt << "\n";
			return ;
		}
		q.pop();
		if (temp > 0 && visited[temp - 1][0] == false)
		{
			visited[temp - 1][0] = true;
			visited[temp - 1][1] = temp;
			q.push(std::make_pair(temp - 1, cnt + 1));
		}
		if (temp + 1 <= 100000 && visited[temp + 1][0] == false)
		{
			visited[temp + 1][0] = true;
			visited[temp + 1][1] = temp;
			q.push(std::make_pair(temp + 1, cnt + 1));
		}
		if (temp * 2 <= 100000 && visited[temp * 2][0] == false)
		{
			visited[temp * 2][0] = true;
			visited[temp * 2][1] = temp;
			q.push(std::make_pair(temp * 2, cnt + 1));
		}
	}
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cin >> n >> k;
	bfs(n);
	s.push(k);
	while (visited[k][1] != -1)
	{
		s.push(visited[k][1]);
		k = visited[k][1];
	}
	while (!s.empty())
	{
		std::cout << s.top() << " ";
		s.pop();
	}
	std::cout << "\n";
}