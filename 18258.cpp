#include <iostream>
#include <string>
#include <queue>

int	main(void)
{
	std::ios_base :: sync_with_stdio(false);
	std::cin.tie(NULL);

	int	n;
	std::cin >> n;
	std::queue<int> queue;
	while (n--)
	{
		std::string str;
		std::cin >> str;
		if (str == "push")
		{
			int	i;
			std::cin >> i;
			queue.push(i);
		}
		else if (str == "pop")
		{
			if (queue.empty())
				std::cout << "-1\n";
			else
			{
				std::cout << queue.front() << "\n";
				queue.pop();
			}
		}
		else if (str == "size")
		{
			std::cout << queue.size() << "\n";
		}
		else if (str == "empty")
		{
			std::cout << queue.empty() << "\n";
		}
		else if (str == "front")
		{
			if (queue.empty())
				std::cout << "-1\n";
			else
				std::cout << queue.front() << "\n";
		}
		else if (str == "back")
		{
			if (queue.empty())
				std::cout << "-1\n";
			else
				std::cout << queue.back() << "\n";
		}
	}
}