#include <iostream>
#include <cmath>

typedef unsigned long long int ll;

double n;

ll	get_front_len(int num)
{
	ll len = 10;
	while (num >= 10)
	{
		len *= 10;
		num /= 10;
	}
	return (10000 * num * (len - 1));
}

void    solve(void)
{
	ll tmp = 100000 - (n * 10000);
	int len = 1;
    int flag = 0;
	ll i = 10;
	if (n == 1)
	{
		i = 1;
		while (i < 10)
			std::cout << i++ << "\n";
	}
    while (i <= 100000000)
    {
		if (get_front_len(i) == tmp * i)
		{
			flag = 1;
			std::cout << i << "\n";
		}
		i++;
    }
    if (flag == 0)
        std::cout << "No solution\n";
}

int main(void)
{
    std::cin >> n;
    if (n >= 10)
    {
        std::cout << "No solution\n";
        return 0;
    }
    solve();
}
