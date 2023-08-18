#include <iostream>

void	fact(unsigned long long *a, unsigned long long i)
{
	if (i < 2)
		return ;
	*a *= i;
	fact(a, i - 1);
}

int	main(void)
{
	unsigned long long	i;
	std::cin >> i;
	unsigned long long	a = 1;
	if (i < 1)
	{
		std::cout << "1" << std::endl;
		return 0;
	}
	fact(&a, i);
	std::cout << a << std::endl;
}