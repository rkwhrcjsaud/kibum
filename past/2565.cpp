#include <iostream>
#include <algorithm>

typedef	struct	t_arr
{
	int left;
	int right;
}	s_arr;

s_arr arr[102];
int	dp[102];
int max;
int n;

int compare(s_arr a, s_arr b)
{
	return a.left < b.left;
}

int main(void)
{
	std::cin >> n;
	int i = 1;
	while (i <= n)
	{
		std::cin >> arr[i].left >> arr[i].right;
		i++;
	}
	std::sort(arr + 1, arr + n + 1, compare);
	i = 1;
	while (i <= n)
	{
		int j = 0;
		while (j < i)
		{
			if (arr[i].right > arr[j].right && dp[i] <= dp[j])
			{
				dp[i] = dp[j] + 1;
				if (max < dp[i])
					max = dp[i];
			}
			j++;
		}
		i++;
	}
	std::cout << n - max << std::endl;
}