#include <iostream>
#include <vector>
#include <algorithm>

int N, M;
std::vector<int> c;
std::vector<int> box;

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cin >> N;
	for (int i = 0; i < N; i++)
	{
		int tmp;
		std::cin >> tmp;
		c.push_back(tmp);
	}
	std::cin >> M;
	for (int i = 0; i < M; i++)
	{
		int tmp;
		std::cin >> tmp;
		box.push_back(tmp);
	}
	std::sort(box.begin(), box.end(), std::greater<int>());
	int ans = 0;
	while (1)
	{
		int prev = box.size();
		for (std::vector<int>::iterator it = c.begin(); it != c.end(); it++)
		{
			std::vector<int>::iterator it2 = std::lower_bound(box.begin(), box.end(), *it, std::greater<int>());
			if (it2 == box.end())
				continue ;
			box.erase(it2);
			if (box.empty())
			{
				std::cout << ans + 1 << '\n';
				return (0);
			}
		}
		if (prev == box.size())
		{
			std::cout << -1 << '\n';
			return (0);
		}
		ans++;
	}
}
