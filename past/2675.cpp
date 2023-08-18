#include <iostream>

int main()
{
	int n;
	std::cin >> n;
	while (n--)
	{
		int m;
		std::cin >> m;
		std::string	str;
		std::cin >> str;
		int i = 0;
		while (i < str.length())
		{
			int j = 0;
			while (j++ < m)
				std::cout << str[i];
			i++;
		}
		std::cout << "\n";
	}
}