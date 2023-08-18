#include <stdio.h>

int	main(void)
{
	int a, b, c, d, e, f, x, y;

	scanf("%d %d %d %d %d %d", &a, &b, &c, &d, &e, &f);
	y = (d * c - a * f) / (d * b - a * e);
	if (a != 0)
		x = (c - b * y) / a;
	else
		x = (f - e * y) / d;
	printf("%d %d", x, y);
}