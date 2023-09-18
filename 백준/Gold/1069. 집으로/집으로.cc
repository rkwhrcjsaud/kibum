#include <iostream>
#include <cmath>

#define MIN(a, b) (a > b ? b : a)

long long X, Y, D, T;
long double	min;

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cin >> X >> Y >> D >> T;
	std::cout << std::fixed;
	std::cout.precision(20);
	long double d = sqrtl(X * X + Y * Y);
	min = d;
	if (D > T)
	{
		long long cnt = 0;
		long double	temp = d;
		while (1)
		{
			temp -= D;
			cnt += T;
			if (min > fabsl(temp) + cnt)
			{
				min = fabsl(temp) + cnt;
				if (temp < D)
					min = MIN(min, cnt + T);
			}
			else
				break ;
		}
		if (D * 2 > d)
			min = MIN(min, T * 2);
	}
	std::cout << min << "\n";
}