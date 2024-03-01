#include <iostream>

long long x, nx, y, ny;

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cin >> x >> y >> nx >> ny;
	long long ans = 0;
	long long dx = x / 2 * 2 + 1;
	for (;dx < nx; dx += 2)
	{
		if (y > dx)
			continue ;
		if (dx > ny)
			ans += ny - y;
		else
			ans += dx - y;
	}
	long long dy = y / 2 * 2 + 1;
	for (;dy < ny; dy += 2)
	{
		if (x > dy)
			continue ;
		if (dy >= nx)
			ans += nx - x;
		else
			ans += dy - x + 1;
	}
	std::cout << ans << '\n';
}
