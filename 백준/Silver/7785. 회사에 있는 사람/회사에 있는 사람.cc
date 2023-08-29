#include <iostream>
#include <set>

int n;
std::set < std::string > s;

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cin >> n;
	int i = 0;
	while (i < n)
	{
		std::string name;
		std::string	enter;
		std::cin >> name >> enter;
		if (enter == "enter")
			s.insert(name);
		else
			s.erase(name);
		i++;
	}
	std::set<std::string>::iterator iter = s.end();
	iter--;
	while (1)
	{
		std::cout << *iter << "\n";
		if (iter == s.begin())
			break ;
		iter--;
	}
}