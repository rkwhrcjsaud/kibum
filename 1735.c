#include <stdio.h>

int	main(void)
{
	int	a, b, c, d;
	scanf("%d %d", &a, &b);
	scanf("%d %d", &c, &d);
	int	head, body;
	head = a * d + c * b;
	body = b * d;
	int big, small;
	big = (head > body) * head + (head <= body) * body;
	small = (head < body) * head + (head >= body) * body;
	while (1)
	{
		if (big % small != 0)
		{
			int	temp;
			temp = big % small;
			big = small;
			small = temp;
		}
		else
			break ;
	}
	printf("%d %d\n", head / small, body / small);
}