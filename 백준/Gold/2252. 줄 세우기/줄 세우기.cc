#include <iostream>
#include <vector>
#include <queue>

int N, M;
std::vector <int> v[32001];
std::queue <int> q;
int	arr[32001];

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cin >> N >> M;
	int i = 0;
	while (i < M)
	{
		int a, b;
		std::cin >> a >> b;
		v[a].push_back(b);
		arr[b]++;
		i++;
	}
	i = 1;
	while (i <= N)
	{
		if (arr[i] == 0)
			q.push(i);
		i++;
	}
	while (!q.empty())
	{
		std::vector <int> temp = v[q.front()];
		std::cout << q.front() << " ";
		q.pop();
		int j = 0;
		int size = temp.size();
		while (j < size)
		{
			if (--arr[temp[j]] == 0)
				q.push(temp[j]);
			j++;
		}
	}
	std::cout << "\n";
}