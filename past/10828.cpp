#include <iostream>
#include <stack>

int	main(void)
{
	int			n;
	int			m;
	std::string	str;
	std::stack<int> stack;

	std::cin >> n;
	m = 0;
	while (m < n)
	{
		std::cin >> str;
		if (str == "push")
		{
			int	temp;
			std::cin >> temp;
			stack.push(temp);
		}
		else if (str == "pop")
		{
			if (stack.empty())
				std::cout << "-1" << std::endl;
			else
			{
				std::cout << stack.top() << std::endl;
				stack.pop();
			}
		}
		else if (str == "size")
			std::cout << stack.size() << std::endl;
		else if (str == "empty")
			std::cout << stack.empty() << std::endl;
		else if (str == "top")
		{
			if (stack.empty())
				std::cout << "-1" << std::endl;
			else
				std::cout << stack.top() << std::endl;
		}
		m++;
	}
}