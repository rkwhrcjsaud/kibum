#include <iostream>

std::string	str;
int	arr[100][2];

int main(void)
{
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);
	std::cin >> str;
	int len = str.length();
	int i = 0;
	int idx = 0;
	while (i < len)
	{
		int temp = 0;
		if (str[i] == '-' || str[i] == '+')
		{
			if (str[i] == '-')
				arr[idx][1] = true;
			i++;
		}
		while (str[i] >= '0' && str[i] <= '9')
		{
			temp = temp * 10 + (str[i] - '0');
			i++;
		}
		arr[idx][0] = temp;
		idx++;
	}
	int limit = idx;
	idx = 1;
	int ans = arr[0][0];
	while (idx < limit)
	{
		int temp = 0;
		if (arr[idx][1])
		{
			temp = arr[idx][0];
			idx++;
			while (idx < limit && !arr[idx][1])
				temp += arr[idx++][0];
		}
		else
		{
			ans += arr[idx][0];
			idx++;
		}
		ans -= temp;
	}
	std::cout << ans << "\n";
}