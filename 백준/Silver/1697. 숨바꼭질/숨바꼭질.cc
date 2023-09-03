#include <iostream>
#include <queue>

int n, k;
bool	visited[100002];
std::queue < std::pair <int, int> > q;

void	bfs(int a)
{
	visited[a] = true;
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
		if (temp > 0 && visited[temp - 1] == false)
		{
			visited[temp - 1] = true;
			q.push(std::make_pair(temp - 1, cnt + 1));
		}
		if (temp + 1 <= 100000 && visited[temp + 1] == false)
		{
			visited[temp + 1] = true;
			q.push(std::make_pair(temp + 1, cnt + 1));
		}
		if (temp * 2 <= 100000 && visited[temp * 2] == false)
		{
			visited[temp * 2] = true;
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
}