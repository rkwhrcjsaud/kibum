#include <iostream>

int N;
bool	arr[21];

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cin >> N;
	int i = 0;
	while (i < N)
	{
		std::string	str;
		std::cin >> str;
		if (str == "all")
		{
			int i = 1;
			while (i <= 20)
				arr[i++] = true;
		}
		else if (str == "empty")
		{
			int i = 1;
			while (i <= 20)
				arr[i++] = false;
		}
		else
		{
			int a;
			std::cin >> a;
			if (str == "add")
				arr[a] = true;
			else if (str == "remove")
				arr[a] = false;
			else if (str == "toggle")
				arr[a] = !arr[a];
			else if (str == "check")
				std::cout << arr[a] << "\n";
		}
		i++;
	}
}