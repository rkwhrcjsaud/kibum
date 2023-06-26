#include <iostream>
#include <stack>
#include <string>

int	main(void)
{
	int				t;
	std::stack<int> stack;

	std::cin >> t;
	while (t--)
	{
		std::string str;
		std::cin >> str;
		int	i = 0;
		while (str[i])
		{
			if (str[i] == '(')
				stack.push(1);
			if (str[i] == ')')
			{
				if (stack.empty())
				{
					stack.push(1);
					break ;
				}
				stack.pop();
			}
			i++;
		}
		if (stack.empty())
			std::cout << "YES" << std::endl;
		else
			std::cout << "NO" << std::endl;
		while (!stack.empty())
			stack.pop();
	}
}