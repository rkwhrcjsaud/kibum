#include <iostream>
#include <set>

int n, cnt;
std::set < std::string > s;

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cin >> n;
	int i = 0;
	cnt = 1;
	s.insert("ChongChong");
	while (i < n)
	{
		std::string temp1, temp2;
		std::cin >> temp1 >> temp2;
		if (s.insert(temp1).second)
			s.erase(temp1);
		else
		{
			if (s.insert(temp2).second)
				cnt++;
		}
		if (s.insert(temp2).second)
			s.erase(temp2);
		else
		{
			if (s.insert(temp1).second)
				cnt++;
		}
		i++;
	}
	std::cout << cnt << "\n";
}