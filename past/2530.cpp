#include <iostream>

int main()
{
	int i = 0;
	int a = 0;
	while (i++ < 3)
	{
		int n;
		std::cin >> n;
		int j = i;
		while (j++ < 3)
			n *= 60;
		a += n;
	}
	int m;
	std::cin >> m;
	a += m;
	int h = a / 3600;
	a = a % 3600;
	m = a / 60;
	a = a % 60;
	while (h >= 24)
		h -= 24;
	std::cout << h << " " << m << " " << a << "\n";
}