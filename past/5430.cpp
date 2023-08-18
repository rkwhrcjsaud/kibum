#include <iostream>
#include <string>
#include <deque>

#define FRONT 0
#define BACK 1

int	main(void)
{
	int	t;
	std::cin >> t;
	std::deque<int> dq;
	while (t--)
	{
		std::string p;
		std::cin.ignore();
		std::cin >> p;
		int	n;
		std::cin >> n;
		size_t	i = 0;
		std::string	temp;
		std::cin >> temp;
		while (i < temp.length() && temp.length() > 2)
		{
			int	num;
			if (temp[i] >= '0' && temp[i] <= '9')
			{
				num = num * 10 + (temp[i] - '0');
			}
			else
			{
				if (temp[i] != '[')
					dq.push_back(num);
				num = 0;
			}
			i++;
		}
		i = 0;
		int	flag = FRONT;
		int	error = 0;
		while (p[i])
		{
			if (p[i] == 'R')
			{
				if (flag == FRONT)
					flag = BACK;
				else
					flag = FRONT;
			}
			else if (p[i] == 'D')
			{
				if (flag == FRONT)
				{
					if (dq.empty())
					{
						error = 1;
						break ;
					}
					dq.pop_front();
				}
				else if (flag == BACK)
				{
					if (dq.empty())
					{
						error = 1;
						break ;
					}
					dq.pop_back();
				}
			}
			else
			{
				error = 1;
				break ;
			}
			i++;
		}
		if (error)
		{
			std::cout << "error\n";
			while (!dq.empty())
				dq.pop_back();
			continue ;
		}
		std::cout << "[";
		while (dq.size())
		{
			if (flag == FRONT)
			{
				if (dq.front())
					std::cout << dq.front();
				dq.pop_front();
			}
			else if (flag == BACK)
			{
				if (dq.back())
					std::cout << dq.back();
				dq.pop_back();
			}
			if (dq.size())
				std::cout << ",";
		}
		std::cout << "]\n";
		while (!dq.empty())
			dq.pop_back();
	}
}