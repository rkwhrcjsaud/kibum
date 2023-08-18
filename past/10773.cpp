#include <iostream>
#include <stack>

int	main(void)
{
	int				k;
	std::stack<int> stack;

	std::cin >> k;
	while (k--)
	{
		int	temp;
		std::cin >> temp;
		if (temp == 0)
		{
			if (!stack.empty())
				stack.pop();
		}
		else
			stack.push(temp);
	}
	int ans;
	ans = 0;
	while (!stack.empty())
	{
		ans += stack.top();
		stack.pop();
	}
	std::cout << ans << std::endl;
}