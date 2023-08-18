#include <iostream>
#include <string>
#include <deque>

int	main(void)
{
	std::ios_base :: sync_with_stdio(false);
	std::cin.tie(NULL);

	int	n;
	std::cin >> n;
	std::deque<int> dq;
	while (n--)
	{
		std::string str;
		std::cin >> str;
		if (str == "push_front")
		{
			int	temp;
			std::cin >> temp;
			dq.push_front(temp);
		}
		else if (str == "push_back")
		{
			int	temp;
			std::cin >> temp;
			dq.push_back(temp);
		}
		else if (str == "pop_front")
		{
			if (dq.empty())
				std::cout << "-1\n";
			else
			{
				std::cout << dq.front() << "\n";
				dq.pop_front();
			}
		}
		else if (str == "pop_back")
		{
			if (dq.empty())
				std::cout << "-1\n";
			else
			{
				std::cout << dq.back() << "\n";
				dq.pop_back();
			}
		}
		else if (str == "size")
			std::cout << dq.size() << "\n";
		else if (str == "empty")
			std::cout << dq.empty() << "\n";
		else if (str == "front")
		{
			if (dq.empty())
				std::cout << "-1\n";
			else
				std::cout << dq.front() << "\n";
		}
		else if (str == "back")
		{
			if (dq.empty())
				std::cout << "-1\n";
			else
				std::cout << dq.back() << "\n";
		}
	}
}