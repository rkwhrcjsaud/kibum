#include <iostream>
#include <vector>

std::string str;
std::string	boom;
std::vector <char> v;

void	check(int i)
{
	int len = v.size();
	int boom_len = boom.size();
	while (len && boom_len)
	{
		if (v[len - 1] != boom[boom_len - 1])
			break ;
		len--;
		boom_len--;
		if (boom_len == 0)
		{
			int temp = boom.size();
			while (temp--)
				v.pop_back();
		}
	}
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cin >> str >> boom;
	int i = 0;
	int len = str.size();
	while (i < len)
	{
		v.push_back(str[i]);
		check(i);
		i++;
	}
	len = v.size();
	if (len)
	{
		int j = 0;
		while (j < len)
			std::cout << v[j++];
		std::cout << "\n";
	}
	else
		std::cout << "FRULA\n";
}