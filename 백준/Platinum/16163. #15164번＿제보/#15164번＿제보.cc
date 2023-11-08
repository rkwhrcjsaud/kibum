#include <iostream>

#define MAX(a, b) (a > b ? a : b)
#define MIN(a, b) (a < b ? a : b)
typedef long long ll;
std::string str;
std::string str2;
int A[4000004];

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cin >> str;
	int i = 0;
	int len = str.length();
	while (i < len)
	{
		str2 += '#';
		str2 += str[i];
		i++;
	}
	str2 += '#';
	int r = 0, p = 0;
	i = 0;
	len = str2.length();
	while (i < len)
	{
		if (i <= r)
			A[i] = MIN(A[2 * p - i], r - i);
		else
			A[i] = 0;
		while (i - A[i] - 1 >= 0 && i + A[i] + 1 < len && str2[i - A[i] - 1] == str2[i + A[i] + 1])
			A[i]++;
		if (r < i + A[i])
		{
			r = i + A[i];
			p = i;
		}
		i++;
	}
	ll max = 0;
	i = 0;
	while (i < len)
	{
		if (A[i] && (i & 1))
			max += A[i] / 2 + 1;
		else if (A[i] && !(i & 1))
			max += A[i] / 2;
		i++;
	}
	std::cout << max << "\n";
}
