#include <iostream>
#include <stack>

int n;
std::stack <int> s;

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cin >> n;
	int i = 0;
	while (i < n)
	{
		int temp1;
		std::cin >> temp1;
		if (temp1 == 1)
		{
			int temp2;
			std::cin >> temp2;
			s.push(temp2);
		}
		else if (temp1 == 2)
		{
			if (s.empty())
				std::cout << "-1\n";
			else
			{
				std::cout << s.top() << "\n";
				s.pop();
			}
		}
		else if (temp1 == 3)
			std::cout << s.size() << "\n";
		else if (temp1 == 4)
		{
			if (s.empty())
				std::cout << "1\n";
			else
				std::cout << "0\n";
		}
		else if (temp1 == 5)
		{
			if (s.empty())
				std::cout << "-1\n";
			else
				std::cout << s.top() << "\n";
		}
		i++;
	}
}