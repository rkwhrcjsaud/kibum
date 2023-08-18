#include <iostream>

int fibo(int i)
{
	if (i == 0)
		return (0);
	if (i == 1)
		return (1);
	return (fibo(i - 2) + fibo(i - 1));
}

int main(void)
{
	int	i;
	std::cin >> i;
	std::cout << fibo(i) << std::endl;
}