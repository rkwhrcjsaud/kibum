#include <iostream>
#include <vector>
#include <queue>

int N;
std::queue < std::pair <int, std::vector <int> > > q;
bool visited[1000002];

void	dfs(void)
{
	int n = N;
	std::vector < int > v;
	q.push(std::make_pair(n, v));
	while (!q.empty())
	{
		int num = q.front().first;
		std::vector <int> v2 = q.front().second;
		q.pop();
		if (num < 1)
			return ;
		if (num == 1)
		{
			std::cout << v2.size() << "\n";
			int i = 0;
			int size = v2.size();
			std::cout << n << " ";
			while (i < size)
			{
				if (v2[i] == 1)
					n = n - 1;
				else if (v2[i] == 2)
					n = n / 2;
				else
					n = n / 3;
				std::cout << n << " ";
				i++;
			}
			return ;
		}
		if (num % 3 == 0 && visited[num / 3] == false)
		{
			visited[num / 3] = true;
			v2.push_back(3);
			q.push(std::make_pair(num / 3, v2));
			v2.pop_back();
		}
		if (num % 2 == 0 && visited[num / 2] == false)
		{
			visited[num / 2] = true;
			v2.push_back(2);
			q.push(std::make_pair(num / 2, v2));
			v2.pop_back();
		}
		if (visited[num - 1] == false)
		{
			visited[num - 1] = true;
			v2.push_back(1);
			q.push(std::make_pair(num - 1, v2));
			v2.pop_back();
		}
	}
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cin >> N;
	dfs();
	std::cout << "\n";
}