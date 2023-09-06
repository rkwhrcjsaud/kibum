#include <iostream>

std::string	str;
int n, m, cnt;

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cin >> n >> m >> str;
	int i = 0;
	while (i < (m - n * 2))
	{
		if (str[i] == 'I')
		{
			int j = i + 1;
			while (j < i + n * 2 + 1)
			{
				if ((j - i) % 2 == 1)
				{
					if (str[j] != 'O')
						break ;
				}
				else
				{
					if (str[j] != 'I')
						break ;
				}
				j++;
			}
			if (j == i + n * 2 + 1)
			{
				cnt++;
				i++;
			}
		}
		i++;
	}
	std::cout << cnt << "\n";
}