#include <iostream>
#include <set>

int n, m;

std::set<std::string> s;
std::set<std::string> s2;

int	main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cin >> n >> m;
	int i = 1;
	while (i <= n)
	{
		std::string	name;
		std::cin >> name;
		s.insert(name);
		i++;
	}
	i = 1;
	while (i <= m)
	{
		std::string name;
		std::cin >> name;
		if (s.find(name) != s.end())
			s2.insert(name);
		i++;
	}
	std::cout << s2.size() << "\n";
	std::set<std::string>::iterator iter = s2.begin();
	while (iter != s2.end())
	{
		std::cout << *iter << "\n";
		iter++;
	}
}