#include <iostream>

int f[1000002];
int	ans;

void dp(int n)
{
	f[0] = 1;
	f[1] = 1;
	int i = 2;
	while (i <= n)
	{
		f[i] = f[i - 1] + f[i - 2];
		if (f[i] > 15746)
			f[i] -= 15746;
		i++;
	}
	ans = f[n];
}

int main()
{
	int n;
	std::cin >> n;
	dp(n);
	std::cout << ans % 15746 << std::endl;
}