#include <iostream>
#include <deque>

int n;
std::deque <int> d;

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cin >> n;
	int i = 0;
	while (i++ < n)
	{
		int temp;
		std::cin >> temp;
		if (temp == 1)
		{
			int temp2;
			std::cin >> temp2;
			d.push_front(temp2);
		}
		else if (temp == 2)
		{
			int temp2;
			std::cin >> temp2;
			d.push_back(temp2);
		}
		else if (temp == 3)
		{
			if (d.empty())
				std::cout << "-1\n";
			else
			{
				std::cout << d.front() << "\n";
				d.pop_front();
			}
		}
		else if (temp == 4)
		{
			if (d.empty())
				std::cout << "-1\n";
			else
			{
				std::cout << d.back() << "\n";
				d.pop_back();
			}
		}
		else if (temp == 5)
			std::cout << d.size() << "\n";
		else if (temp == 6)
			std::cout << d.empty() << "\n";
		else if (temp == 7)
		{
			if (d.empty())
				std::cout << "-1\n";
			else
				std::cout << d.front() << "\n";
		}
		else if (temp == 8)
		{
			if (d.empty())
				std::cout << "-1\n";
			else
				std::cout << d.back() << "\n";
		}
	}
}