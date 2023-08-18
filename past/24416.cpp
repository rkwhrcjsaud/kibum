#include <iostream>

int f[50];
int	fib_n;
int fibonacci_n;

int fib(int n) {
    if (n == 1)
		return 1;
	else if (n == 2)	
		return 1;
	fib_n++;
    return (fib(n - 1) + fib(n - 2));
}

int fibonacci(int n) {
	f[0] = 0;
    f[1] = 1;
	f[2] = 1;
	int i = 3;
	while (i < n)
	{
		fibonacci_n++;
		f[i] = f[i - 1] + f[i - 2];
		i++;
	}
	return f[n];
}

int main(void)
{
	int n;
	std::cin >> n;
	fib(n);
	fibonacci(n);
	fib_n++;
	fibonacci_n++;
	std::cout << fib_n << " " << fibonacci_n << std::endl;
}