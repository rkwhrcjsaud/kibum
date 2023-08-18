#include <iostream>
#include <algorithm>

typedef struct	t_arr
{
	int	start;
	int end;
}	s_arr;

int n, cnt;
s_arr	arr[100002];

int compare(s_arr a, s_arr b)
{
	if (a.end < b.end)
		return (true);
	else if (a.end == b.end && a.start < b.start)
		return (true);
	return (false);
}

int main(void)
{
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);
	std::cin >> n;
	int i = 0;
	while (i < n)
	{
		std::cin >> arr[i].start >> arr[i].end;
		i++;
	}
	std::sort(arr, arr + n, compare);
	i = 0;
	std::cout << "\n";
	while (i < n)
	{
		std::cout << arr[i].start << " " << arr[i].end << "\n";
		i++;
	}
	i = 1;
	cnt++;
	while (i < n)
	{
		int temp = arr[i - 1].end;
		while (arr[i].start < temp && i < n)
			i++;
		if (i == n)
			break ;
		cnt++;
		i++;
	}
	std::cout << cnt << "\n";
}