#include <iostream>
#include <set>

int n, cnt;
std::set<std::string> s;

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cin >> n;
	int i = 0;
	while (i < n)
	{
		std::string temp;
		std::cin >> temp;
		if (temp == "ENTER")
			s.clear();
		else
			if (s.insert(temp).second)
				cnt++;
		i++;
	}
	std::cout << cnt << "\n";
}