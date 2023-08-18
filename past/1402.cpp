#include <iostream>

int n;

int main(void)
{
	std::ios_base :: sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cin >> n;
	while (n--)
	{
		int a, b;
		std::cin >> a >> b;
		std::cout << "yes\n";
	}
}