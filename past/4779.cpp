#include <iostream>

void	kanto(char *str, int left, int right)
{
	if (right > left)
	{
		int interval = (right - left + 1) / 3;
		kanto(str, left, left + interval - 1);
		while (left + interval <= right - interval)
		{
			str[left + interval] = ' ';
			left++;
		}
		kanto(str, right - interval + 1, right);
	}
}

int main(void)
{
	int n;
	std::cin >> n;
	while (!std::cin.eof())
	{
		int m = 1;
		while (n--)
			m *= 3;
		char str[m + 1];
		int i = 0;
		while (i < m)
			str[i++] = '-';
		str[m] = 0;
		kanto(str, 0, m - 1);
		std::cout << str << std::endl;
		std::cin >> n;
	}
}