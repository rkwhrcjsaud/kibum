#include <iostream>
#include <map>

int T, F;
std::map < std::string, std::pair < std::string, int > > s;

std::string find_root(std::string str)
{
	if (str != s.find(str)->second.first)
		return (s.find(str)->second.first = find_root(s.find(str)->second.first));
	return (str);
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cin >> T;
	while (T--)
	{
		std::cin >> F;
		int i = 0;
		while (i < F)
		{
			std::string friend1, friend2;
			std::cin >> friend1 >> friend2;
			std::map < std::string, std::pair < std::string, int > >
				::iterator iter1 = s.find(friend1);
			if (iter1 == s.end())
				s.insert(std::make_pair(friend1, std::make_pair(friend1, 1)));
			std::map < std::string, std::pair < std::string, int > >
				::iterator iter2 = s.find(friend2);
			if (iter2 == s.end())
				s.insert(std::make_pair(friend2, std::make_pair(friend2, 1)));
			std::string root_1 = find_root(friend1);
			std::string root_2 = find_root(friend2);
			if (root_1 != root_2)
			{
				std::map < std::string, std::pair < std::string, int > >
					::iterator iter = s.find(root_2);
				iter->second.first = root_1;
				s.find(root_1)->second.second += iter->second.second;
			}
			std::cout << s.find(root_1)->second.second << "\n";
			i++;
		}
		s.clear();
	}
}