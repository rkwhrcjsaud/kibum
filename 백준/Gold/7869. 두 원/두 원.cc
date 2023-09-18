#include <iostream>
#include <cmath>

#define PI 3.14159265
#define MIN(a, b) (a < b ? a : b)

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	long double	x1, y1, r1, x2, y2, r2;
	std::cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
	long double	d = sqrtl((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
	std::cout << std::fixed;
	std::cout.precision(3);
	long double	area = 0;
	if (r1 + r2 <= d)
		area = 0;
	else if (fabsl(r1 - r2) >= d)
		area = PI * MIN(r1, r2) * MIN(r1, r2);
	else
	{
		long double	t1 = 2 * acosl((d * d + r1 * r1 - r2 * r2) / (2 * d * r1));
		long double	t2 = 2 * acosl((d * d + r2 * r2 - r1 * r1) / (2 * d * r2));
		area += (t1 * r1 * r1 + t2 * r2 * r2) / 2 - r1 * sinl(t1 / 2) * r1 * cosl(t1 / 2)
			- r2 * sinl(t2 / 2) * r2 * cosl(t2 / 2);
	}
	std::cout << area << "\n";
}