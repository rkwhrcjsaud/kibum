#include <iostream>
#include <set>

std::set<std::string> s;
int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::string	str;
	std::cin >> str;
	int len = str.length();
	int i = 0;
	while (i < len)
	{
		int j = i + 1;
		while (j <= len)
		{
			s.insert(str.substr(i, j - i));
			j++;
		}
		i++;
	}
	std::cout << s.size() << "\n";
}