#include <iostream>

void move(char from, char to)
{
    std::cout << from << " " << to << "\n";
}

void hanoi(int n, char from, char by, char to)
{
    if(n == 0)
		return ;
    hanoi(n - 1, from, to, by);
    move(from, to);
    hanoi(n - 1, by, from, to);
}

int main(void)
{
	int n;
	std::cin >> n;
	int	a = 1;
	a = a << n;
	std::cout << a - 1 << "\n";
	hanoi(n, '1', '2', '3');
}