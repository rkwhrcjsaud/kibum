#include <iostream>
#include <stack>
#include <string>

int	main(void)
{
	std::stack<int> stack;
	std::string		str;
	int	len;

	std::cin >> len;
	int	arr[len];
	int i = 0;
	str = "";
	while (i < len)
		std::cin >> arr[i++];
	i = 0;
	int	j = 1;
	while (i < len)
	{
		if (arr[i] >= j)
		{
			while (arr[i] >= j)
			{
				str += "+\n";
				stack.push(j++);
			}
			str += "-\n";
			stack.pop();
		}
		else
		{
			if (stack.top() == arr[i])
			{
				str += "-\n";
				stack.pop();
			}
			else
			{
				std::cout << "NO" << std::endl;
				return (0);
			}
		}
		i++;
	}
	std::cout << str;
}