#include <iostream>

int M;
long long	fibo[50];

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cin >> M;
	fibo[0] = 6;
	fibo[1] = 14;
	int n = 2;
	while (1)
	{
		fibo[n] = fibo[n - 1] + fibo[n - 2];
		if (fibo[n] > M)
			break ;
		n++;
	}
	while (n != 0 && n != 1)
	{
		if (M - fibo[n - 1] > 0)
		{
			M -= fibo[n - 1];
			n -= 2;
		}
		else
			n--;
	}
	std::string	str = "Messi Gimossi ";
	if (n == 0)
	{
		if (str[M - 1] == ' ')
			std::cout << "Messi Messi Gimossi\n";
		else
			std::cout << str[M - 1] << "\n";
	}
	else if (n == 1)
	{
		if (str[M - 1] == ' ')
			std::cout << "Messi Messi Gimossi\n";
		else
			std::cout << str[M - 1] << "\n";
	}
}