#include <iostream>
#include <string>
#include <stack>

int	main(void)
{
	std::stack<int> st;
	std::string		str;
	getline(std::cin, str, '\n');
	while (!(str[0] == '.' && str.length() == 1))
	{
		int	i = 0;
		while (str[i])
		{
			if (str[i] == '(')
				st.push(1);
			else if (str[i] == ')')
			{
				if (st.empty() || st.top() == 2)
				{
					st.push(1);
					break ;
				}
				st.pop();
			}
			else if (str[i] == '[')
				st.push(2);
			else if (str[i] == ']')
			{
				if (st.empty() || st.top() == 1)
				{
					st.push(2);
					break ;
				}
				st.pop();
			}
			i++;
		}
		if (st.empty() && st.empty())
			std::cout << "yes" << std::endl;
		else
			std::cout << "no" << std::endl;
		while (!st.empty())
			st.pop();
		getline(std::cin, str, '\n');
	}
}