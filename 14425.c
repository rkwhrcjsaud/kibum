#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	compare(const void *s1, const void *s2)
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

int	count_str(char *str, char **buf, int left, int right)
{
	int	mid;

	while (left <= right)
	{
		mid = (left + right) / 2;
		if (strcmp(str, buf[mid]) == 0)
			return (1);
		if (strlen(str) > strlen(buf[mid]))
			left = mid + 1;
		else if (strlen(str) < strlen(buf[mid]))
			right = mid - 1;
		else
		{
			if (strcmp(str, buf[mid]) > 0)
				left = mid + 1;
			else if (strcmp(str, buf[mid]) < 0)
				right = mid - 1;
		}
	}
	return (0);
}

int	main(void)
{
	int		n, m;
	scanf("%d %d", &n, &m);
	char	**buf;
	char	**buf2;
	buf = (char **)malloc(sizeof(char *) * (n + 1));
	buf[n] = NULL;
	buf2 = (char **)malloc(sizeof(char *) * (m + 1));
	buf2[m] = NULL;
	int	i = 0;
	while (i < n)
	{
		buf[i] = (char *)malloc(sizeof(char) * 501);
		buf[i][500] = 0;
		scanf("%s", buf[i]);
		i++;
	}
	i = 0;
	while (i < m)
	{
		buf2[i] = (char *)malloc(sizeof(char) * 501);
		buf2[i][500] = 0;
		scanf("%s", buf2[i]);
		i++;
	}
	qsort(buf, n, sizeof(char *), compare);
	int	cnt = 0;
	i = 0;
	while (i < m)
	{
		cnt += count_str(buf2[i], buf, 0, n - 1);
		i++;
	}
	printf("%d", cnt);
}