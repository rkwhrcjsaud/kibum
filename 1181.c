#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int	compar(const void *s1, const void *s2)
{
	const char	*cs1;
	const char	*cs2;
	size_t		cs1len;
	size_t		cs2len;

	cs1 = *(const char **)s1;
	cs2 = *(const char **)s2;
	cs1len = strlen(cs1);
	cs2len = strlen(cs2);
	if (cs1len > cs2len)
		return (1);
	else if (cs1len < cs2len)
		return (-1);
	else if (strcmp(cs1, cs2) > 0)
		return (1);
	else if (strcmp(cs1, cs2) < 0)
		return (-1);
	return (0);
}

int	main(void)
{
	int		n;

	scanf("%d", &n);
	char	**buf;

	buf = (char **)malloc(sizeof(char *) * (n + 1));
	buf[n] = NULL;
	int	i = 0;
	while (i < n)
	{
		buf[i] = (char *)malloc(sizeof(char) * 51);
		buf[i][50] = 0;
		scanf("%s", buf[i]);
		i++;
	}
	qsort(buf, n, sizeof(char *), compar);
	i = 0;
	while (i < n)
	{
		int	j = 0;
		while (j < i)
		{
			if (!strcmp(buf[i], buf[j]))
				break ;
			j++;
		}
		if (j == i)
			printf("%s\n", buf[i]);
		i++;
	}
}
